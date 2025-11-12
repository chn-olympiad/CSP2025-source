#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,a,b,cnt=0;
	cin>>n>>k;
	if(n<=2){
		if(n==1){
			cin>>a;
			if(a==0)cnt++;
		}else{
			cin>>a>>b;
			if(a==0)cnt++;
			if(b==0)cnt++;
			if(a==b&&a!=0)cnt++;
		}
	}else{
		for(ll i=1;i<=n;i++)cin>>a[i];
		for(ll i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
				continue;
			}
			if(a[i]==a[i-1]){
				cnt++;
				a[i]=-1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
