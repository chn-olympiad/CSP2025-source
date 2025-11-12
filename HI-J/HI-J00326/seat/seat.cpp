#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[10005];
bool comp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll num=n*m;
	for(int i=1;i<=num;i++){
		scanf("%lld",&a[i]);
	}
	ll x=a[1];//小R分数 
	sort(a+1,a+1+num,comp);
	ll y=0;
	for(int i=1;i<=num;i++){
		if(a[i]==x){
			y=i;
			break;
		}
	}
	//cout<<y<<endl;
	//列
	ll l=y/n;
	if(y%n!=0) l+=1;
	//cout<<l<<endl;
	//行
	ll r=y%n;
	if(r==0){
		if(l%2!=0){
			printf("%lld %lld",l,n);
			return 0;
		}
		else{
			printf("%lld %lld",l,1);
			return 0;
		}
	}
	//cout<<r<<endl;
	ll ans=0;
	if(l%2==0){
		ans=n-r+1;
	}
	else{
		ans=r;
	}
	printf("%lld %lld",l,ans); 
	return 0;
}
