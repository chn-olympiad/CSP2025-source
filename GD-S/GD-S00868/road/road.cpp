#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[10005][10005];
	long long ans1=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
		ans1+=w;
	}
	int t[15];
    vector<int>ve;
    long long ans2=0;
	for(int i=1;i<=k;i++){
		cin>>t[i];
		for(int i=1;i<=n;i++){
		    int o;
		    cin>>o;
		    ve.push_back(o);
		    ans2+=o;
		}
	}
	long long ans=max(ans1,ans2);
	cout<<ans;
	return 0;
}
