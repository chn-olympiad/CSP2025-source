#include<bits/stdc++.h>
using namespace std;
struct st{
	int p,t,v;
};
int n,m,k,f[100005],ans=INT_MAX,pos=0;
vector<st>g;
int mo[15],mov[15][10005];
int find(int x){
	if(f[x]==x)return x;
	else return find(f[x]);
}bool cmpp(st aa,st bb){
	return aa.v<bb.v;
}void build_check(string s){
	vector<st>tp;
	tp=g;
	for(int i=1;i<=100000;i++)f[i]=i;
	int ans2=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			ans2+=mo[i+1];
			for(int j=1;j<=n;j++){
				st xxx;xxx.p=pos+i+1;xxx.t=j;xxx.v=mov[i+1][j];
				tp.push_back(xxx);pos++;
			}
		}
	}
	sort(tp.begin(),tp.end(),cmpp);
	int sum=0;
	for(int i=1;i<=m+pos;i++){
		if(find(tp[i].p)==find(tp[i].t))continue;
		else f[tp[i].p]=tp[i].t;
		sum++;ans2+=tp[i].v;
		cout << tp[i].p << " " << tp[i].t << "\n"; 
		if(sum==m+pos-1)break;
	}pos=0;
	ans=min(ans,ans2);
	//cout << "-----" << ans2 << "-----\n";
	return;
}
void dfs(string s){
	if(s.size()==k){
		build_check(s);
		return;
	}
	dfs(s+"0");
	dfs(s+"1");
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		g.push_back({x,y,z});
		g.push_back({y,x,z});
	}for(int i=1;i<=k;i++){
		int x;
		cin >> x;mo[i]=x;
		for(int j=1;j<=n;j++){
			int y;
			cin >> y;
			mov[i][j]=y;
		}
	}
	dfs("");
	cout << ans;
	return 0;
}
//我是入 
//我是入 
//我是入 
//我是入 
//我是入 
