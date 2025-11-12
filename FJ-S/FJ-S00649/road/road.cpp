#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	int c,a;
	for(int i=1;i<=k;i++){
		cin>>c;
		int ans=c;
		for(int j=1;j<=m;j++){
			cin>>a;
			ans+=a;
		}
		if(i==1){
			sum=ans;
		}
		sum=min(sum,ans);
	}
	cout<<sum;
	return 0;
} 
