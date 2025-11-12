//×îÐ¡Éú³ÉÊ÷£¬µãÈ¨ÔõÃ´°ì£¬ºÃÁË×îÐ¡Éú³ÉÊ÷Ò²Íü¼ÇÔõÃ´Ð´ÁËShift+6
#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,c[15],a[15][10004],f[10019],r[10019],ans=INT_MAX;
struct Edges{
	int v,w;
};
struct idEdges{
	int u,v,w;
	//îÆ 
};
vector<Edges>e[10004];
map<int,bool>allow;
vector<int>point;
int find(int x) {
	if(f[x]==x) {
		return f[x];
	}
	else {
		f[x]=find(f[x]);
		return f[x];
		//Ñõ 
	}
}
void merge(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
//	if(r[x]>r[y]) {
//		f[y]=fx;
//	}
//	else if(r[x]<r[y]) {
//		f[x]=fy;
//	}
//	else {
//		f[y]=fx;
//		r[x]++;
//	}
	f[x]=fy;
}
void add_edge(int ku) {
	for(int i=1;i<=n;i++) {
		e[i].push_back({n+ku,a[ku][i]});
		e[n+ku].push_back({i,a[ku][i]});
	}
}
bool cmp(idEdges a,idEdges b) {
	return a.w<b.w;
	//ÓË 
}
void mct(int np,int more) {
	int res=more;
	vector<idEdges>ne;
	for(int i=0;i<point.size();i++) {
		for(int j=0;j<e[i].size();j++) {
			ne.push_back({point[i],e[i][j].v,e[i][j].w});
			ne.push_back({e[i][j].v,point[i],e[i][j].w});
		}
	}
	sort(ne.begin(),ne.end(),cmp);
//	for(int i=0;i<ne.size();i++) {
//		printf("%d->%d:%d\n",ne[i].u,ne[i].v,ne[i].w);
//	}
//	printf("\n\n");
	int cnt=0;
	for(int i=0;i<ne.size();i++) {
		if(cnt==np-1) break;
		int u=ne[i].u,v=ne[i].v,w=ne[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		res+=w;
		cnt++;
	}
	ans=min(ans,res);
}
void dfs(int cur,int cnt,int need) {
	if(cnt==need) {
		point.clear();
		for(int i=1;i<=n;i++) point.push_back(i);
		int more=0;
		for(int i=1;i<=k;i++) {
			if(allow[i]) {
				more+=c[i];
				point.push_back(i);
				add_edge(i);
			}
		}
//		printf("need=%d\tmore=%d\n",need,more);
		mct(n+need,more);
	}
	for(int i=cur+1;i<=k;i++) {
		dfs(i,cnt,need);
		allow[i]=1;
		dfs(i,cnt+1,need);
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i; 
	vector<int>pianfen;
	for(int i=1;i<=m;i++) {
		cin>>x>>y>>z;
		panfen.push_back(z);
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	}
	sort(pianfen.begin(),pianfen.end());
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	int ss=0;
	for(int i=1;i<=m;i++) {
		ss+=pianfen[i];
	}
//	for(int i=1;i<=k;i++) {
//		dfs(1,0,i);
//		dfs(1,1,i);
//	}

	cout<<ss;
	return 0;
}
/*
luogu id:1*4*0*4
Save me from €€¡ê!
I will be killed by €¡çP-¡ç!
What am I thinking about,I used to want to get a second grade award in it?
I just not want to have a score of 0 in the exam of €¡çP-¡ç!
I only waste another 1.5h on this problem! 
Tell me why I get such a ÈõÖÇµÄ answer?!
OI!See You Again!
îÆ Ñõ ÓË 
keywords:
feropen
club.cpp
road.cpp
replace.cpp
employ.cpp
clud
clab
raod
repalce
repacle
empty
emplay
enploy
"r",stdout
"w",stdin
ccf
luogu
kkksc03
Ren5Jie4Di4Ling5%
AK
IOI
CSP
CSP-S
CSP-J
NOIp
NOI
APIO
ICPC
WC
freopen("D:\GD-S03177\club\road.in","r",stdin);
freopen("D:\GD-S03177\club\road.out","w",stdout);
*/
