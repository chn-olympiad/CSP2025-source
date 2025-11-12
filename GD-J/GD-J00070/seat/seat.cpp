#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[1000010],ans,j,ans2;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	} 
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		j=n*m-i+1;
		if(a[i]==r){
			if(j%m){
				ans=j%m;
				ans2=j/m;
			}else{
				ans=m;
				ans2=j/m-1;
			}
			if(ans2%2){
				cout<<ans2+1<<" "<<n-ans+1;
			}else{
				cout<<ans2+1<<" "<<ans;
			}
			return 0;
		}
	}
	return 0;
}
