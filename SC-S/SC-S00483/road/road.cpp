#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[10005][10005];
bool a1[10005];
int n,m,k,ans=999999999;
int v1,v2,w,big,big1;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout); 
	cin>>n>>m>>k; 
	if(k==0){
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				a[i][j]=-1;
		for(int i=0;i<m;++i){
			cin>>v1>>v2>>w;
			a[v1-1][v2-1]=w;
			a[v2-1][v1-1]=w;
			ans+=w;
		}

		cout<<ans;
		return 0;
	}
	
	
	
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			a[i][j]=-1;
	for(int i=0;i<m;++i){
		cin>>v1>>v2>>w;
		a[v1-1][v2-1]=w;
		a[v2-1][v1-1]=w;
	}
	int a[k][n+1];
	big=999999999;
	for(int i=0;i<k;++i){
		big1=0;
		for(int j=0;j<=n;++j){
			cin>>a[i][j];
			big1+=a[i][j];
		}
		if(big>big1)big=big1;
	}
	big1=0;
	return 0;
}