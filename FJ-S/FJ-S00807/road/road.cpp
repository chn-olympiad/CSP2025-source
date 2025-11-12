#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans=0;
int city[10001][2],cost[1001],change[1001],cs[1001][1001];
int p(int n){
	for(int i=0;i<n;i++){
		if(cost[i]>cost[i+1]){
			int f=cost[i];
			cost[i]=cost[i+1];
			cost[i+1]=f;
		}
	}	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>city[i][1]>>city[i][2]>>cost[i];
	}
	for(int i=0;i<k;i++){
		cin>>change[i];
		for(int j=0;j<n;j++){
			cin>>cs[i][j];
		}
	}
	p(n);
	p(n);
	ans=cost[0]+cost[1];
	if(change[0]<change[1]){
		ans=ans+change[0];
	}
	else{
		ans=ans+change[1];
	}
	ans+=cs[1][0]+cs[1][2];
	cout<<ans;
	return 0; 
}
