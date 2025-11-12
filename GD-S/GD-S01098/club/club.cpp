#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	//freopen(club.in,'w',stdin);
//	freopen(club.out,'r',stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		int ans=0;
		cin>>n;
		ll a[n][3],b[n][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++) cin>>a[i][j];
		}
		for(int i=0;i<n;i++){
			if(a[i][1]==0&&a[i][0]==0) ans+=a[i][2];
			if(a[i][1]==0&&a[i][2]==0) ans+=a[i][0];
			if(a[i][2]==0&&a[i][0]==0) ans+=a[i][1];
			else ans+=max(max(a[i][0],a[i][1]),max(a[i][1],a[i][2]));
		}	
		cout<<ans<<" ";
		}
	return 0;
} 
