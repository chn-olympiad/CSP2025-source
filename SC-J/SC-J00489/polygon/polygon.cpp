#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,a[5050];
ll ans=0,cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		ll b=a[1]+a[2]+a[3];
		ll c=a[3];
		if(b>c*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if (n<3)cout<<0;return 0;
	
	
	
	
	
	return 0;
}
