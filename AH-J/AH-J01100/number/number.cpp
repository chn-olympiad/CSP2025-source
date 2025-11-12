#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll x,ll y){
	return x>y;
	}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string f;
	ll qwe=0;
	cin>>f;
	ll n=f.size(),a=0,b[1000000];
	for(ll i=0;i<=n;i++){
		if(f[i]<='9'&&f[i]>='0'){
			a=a*10+int(f[i]-'0');
			qwe++;
		}
	}
	for(ll i=1;i<=qwe;i++){
		b[i]=a%10;
		a/=10;
	}
	sort(b+1,b+1+n,cmp);
	for(ll i=1;i<=qwe;i++){
		cout<<b[i];
	}
	return 0;
}
