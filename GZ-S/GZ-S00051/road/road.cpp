//GZ-S00051 北师大附中 刘子逍
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n,m,p,ans;
vector<int> v[10010];
vector<int> w[10010];
bool f[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>p;
	for(int i=1;i<=n;++i){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back(y);
		w[x].push_back(z);
		v[y].push_back(x);
		w[y].push_back(z);
	}
	int mn,inx;
	for(int i=1;;i=inx){
		mn=1e9;
		for(int j=0;j<v[i].size();++j) if(w[i][j]<mn && f[v[i][j]]==0) mn=w[i][j],inx=v[i][j];
		if(mn==1e9) break;
		ans+=mn;
		f[inx]=1;
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
