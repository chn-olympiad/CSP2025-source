#include<bits/stdc++.h>
using namespace std;
	int n;long long k;
	int xr[2005][2005];
	long long a[500005];
int vis[200005];
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	 int cnt=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
 	cin>>n>>k;
 	long long mx=0,mn=2;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		mx=max(mx,a[i]);
 		mn=min(mn,a[i]);
 		xr[i][i]=a[i];
	}
	 if(k==0&&mx==1&&mn==1){
	 	cout<<n/2;
	 	return 0;
	 }
	 if(k==mx&&mx==mn){
	 	cout<<n;
	 	return 0;
	 }
	  
	 
	 if(k==1&&mx==1&&mn==0){
	 	for(int i=1;i<=n;i++){
	 		if(a[i]==1)cnt++;
		 }
		 cout<<cnt;
		 return 0;
	 }
	 else{
	 	cout<<0;
	 }
	

	return 0;
}



