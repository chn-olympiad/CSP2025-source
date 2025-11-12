#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,a[maxn][5],ans=0,sum=0;
int main(){
	freopen("club.in","r",stdin);
  	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if (n==2){
			ans=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			ans=max(a[1][2]+a[2][1],ans);
			ans=max(a[1][2]+a[2][3],ans);
			ans=max(a[1][3]+a[2][1],ans);
			ans=max(a[1][3]+a[2][2],ans);
			cout<<ans;
			return 0;
		}
	}
	return 0;
} 
