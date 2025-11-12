#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;int ans=0;
int u[10010],v[10010],w[10010],c[15],a[10010];
signed main(){
freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i]>>w[i];}
		for(int i=1;i<=k;++i){
			cin>>c[i];
			for(int j=1;j<=n;++j){
				cin>>a[j];}}
				
				
				for(int i=1;i<=n;++i){
					ans+=w[i];}
					cout<<ans<<endl;
					return 0;}
