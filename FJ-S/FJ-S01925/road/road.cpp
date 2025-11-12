#include<iostream>
#include<cstdio>
#include<algorithm>
int n,m,k;
int x[1000010];
int y[1000010];
int w[1000010];
int ans=0;
int k[1000010];
int main(){
	freopen("road.in","r",stdin);
	freoprn("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
	    for(int j=1;j<=n+1;j++){
	    	cin>>k[j];
		}	
	}
	sort(w+1,w+m+1);
	for(int i=1;i<=n-1;i++){
		ans+=w[i];
	}
	cout<<ans<<endl;
	return 0;
}
