#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,m,gs,z1,zs;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	zs=n*m;
	scanf("%lld",&z1);
	ll aa;
	for(ll i=2;i<=zs;i++){
		scanf("%lld",&aa);
		if(aa>z1)gs++;
	}
	ll H=gs%n+1,L=gs/n+1;
	if(!(L&1)){
		H=n-H+1;
	}
//	cout<<gs<<endl;
	printf("%lld %lld",L,H);
	return 0;
}
//12 7 6 1
//11 8 5 2
//10 9 4 3
