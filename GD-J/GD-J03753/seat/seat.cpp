#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6;
ll n,m;
ll a[N];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	ll r=0;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	ll num=0;
	ll hang=1,lie=1;
	bool f=0;
	for(ll i=1;i<=n*m;i++){
		if(a[i]==r){
			printf("%lld %lld",hang,lie);
			break;
		}
		if(f==0){
			lie++;
			if(lie>n){
				hang++;
				lie--;
				f=1;
			}
		}
		else{
			lie--;
			if(lie<1){
				hang++;
				lie++;
				f=0;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
2 2
99 100 97 98
1 2

2 2
98 99 100 97
2 2

3 3
94 95 96 97 98 99 100 93 92
3 1

*/
