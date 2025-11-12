#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
struct seatnum{
	ll num,top;
}a[105];
bool tmp(seatnum x,seatnum y){
	return x.num>y.num;
}
ll if_different(ll x){
	if(x%n==0){
		printf("%lld ",x/n);
		if((x/n)&1)printf("%lld",n);
		else printf("%d",1);
	}
	else{
		printf("%lld ",x/n+1);
		if((x/n+1)&1)printf("%lld",x%n);
		else printf("%lld",n-x%n+1);
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll nm=n*m;
	for(ll i=1;i<=nm;i++){
		cin>>a[i].num;
		a[i].top=i;
	}
	sort(a+1,a+1+nm,tmp);
	for(ll i=1;i<=nm;i++)
		if(a[i].top==1){
			if_different(i);
			return 0;
		}
	
	return 0;
}
