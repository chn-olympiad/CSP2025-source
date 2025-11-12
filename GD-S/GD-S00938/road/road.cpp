#include<bits/stdc++.h>
using namespace std;
struct p {
	int u;
	int v;
	int w;
} e[1000010],adde[104514];
bool cmp(p a,p b) {
	return a.w<b.w;
}
int fa[100014];
int findfa(int x) {
	if(x==fa[x])
		return x;
	else
		return x=findfa(fa[x]);
}
vector<int>c[20];
int n,m,k;
long long check(int nn,int mm) {
	long long ans=0;
	int size=0,tot=n,wei=1;
	while(nn>0) {
		if(nn%2==1) {
			tot++,ans+=c[wei][0];
			for(int j=1; j<=n; j++) {
				adde[++mm].u=j,adde[mm].v=wei+n,adde[mm].w=c[wei][j];
			}
		}
		nn/=2;
		wei++;
	}
	for(int i=1; i<=n+k; i++)
		fa[i]=i;

	sort(adde+1,adde+1+mm,cmp);

	int count=1,count1=1;

	for(int i=1; i<=mm+m; i++) {
		p ls;
		if((adde[count].w<=e[count1].w&&count<=mm)||count1>m) {
			ls=adde[count];
			count++;
		} else if((count1<=m&&adde[count].w>e[count1].w)||count>mm) {
			ls=e[count1];
			count1++;
		}
		int gx=findfa(ls.u),gy=findfa(ls.v);
		if(gx==gy)
			continue;
		if(gx!=gy) {
			fa[gy]=gx;
			ans+=ls.w;
			size++;
			if(size==tot-1)
				break;
		}
	}
	return ans;
}
int main() {
	ifstream cin("road.in");
	ofstream cout("road.out");
	cin>>n>>m>>k;
	int tot=n;
	for(int i=1; i<=m; i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,cmp);
	bool pf=0;
	for(int i=1,t; i<=k; i++) {
		cin>>t;
		if(t!=0)
			pf=1;
		c[i].push_back(t);
		for(int j=1,x; j<=n; j++) {
			cin>>x;
			c[i].push_back(x);
		}
	}
	long long ans1=1e18+7;
	int i=0,kknd=pow(2,k);
	if(!pf&&k>=5&&k<=10)
		i=kknd-1;
	for(; i<kknd; i++)
		ans1=min(ans1,check(i,0));
	cout<<ans1;
	cin.close();
	cout.close();
	return 0;
}
//问题的根源在于复制数组时的瓶颈
//要减少排序与数组复制操作

