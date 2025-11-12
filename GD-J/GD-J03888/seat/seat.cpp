#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],sum=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])sum++;
	}
	int ans=sum/n;
	if(sum%n!=0)ans++;
	if(ans%2==1){
		if(sum%n==0)cout<<ans<<" "<<n;
		else cout<<ans<<" "<<sum%n;
	}
	else{
		if(sum%n==0)cout<<ans<<" "<<1;
		else cout<<ans<<" "<<n-sum%n+1;
	}
	return 0;
}
