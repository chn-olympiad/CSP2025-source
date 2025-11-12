#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,mx=INT_MIN,a[5005],ans=0;
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	scanf("%lld",&n);
	if(n==3){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(mx<a[i])mx=a[i];
			ans+=a[i];
		}
		if(ans>mx*2){
			printf("1");
		}
		else printf("0");		
	}
	else printf("9");
	return 0;
} 
