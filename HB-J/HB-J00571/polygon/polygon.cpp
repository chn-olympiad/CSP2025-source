#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,a[5010],b[5010],ans=0;
void quan(ll x,ll cnt,ll q){
	if(x>cnt){
		ll num=0;
		for(int i=1;i<x;i++){
			num+=b[a[i]];
		}
		if(num>b[a[x-1]]*2){
			ans++;
		}
		return;
	}
	for(int i=x;i<=q;i++){
		if(n-i<cnt-x) continue;
		if(i<=a[x-1]) continue;
		a[x]=i;
		quan(x+1,cnt,n);
		a[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=3;i<=n;i++) quan(1,i,n);
	cout<<ans;
	return 0;
}
