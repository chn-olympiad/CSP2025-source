#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5*5+114514;
ll n,k,sum,kk,ans;
bool huragu=false;
ll a[N];
void boku(ll l,ll r){
	if(l==r){
		kk=a[l];
	}
	else{
		for(register ll i=l+1;i<=r;i++){
		kk^=a[i];
	}	
	}
	if(kk==k)
	{
		sum++;
		huragu=true;
	}
}
void solve(){
	memset(a,0,sizeof(a));
	for(register ll i=1;i<=n;i++)
	cin>>a[i];
	for(register ll i=1;i<=n;i++){
		for(register ll j=i;j<=n;j++){
			boku(i,j);
		if(huragu==1){
			huragu=false;
			i=j+1;
		}
		}
	}
	cout<<sum;
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
solve();
return 0;
}
