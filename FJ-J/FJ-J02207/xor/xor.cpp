#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],ans,sum,l;
bool ok=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		sum=l=0;
		ok=false;
		for(ll j=i;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				ok=true;
				ans++;
				l=j;
				break;
			}
		}
		if(ok==true){
			i=l;
		}
	}
	cout<<ans;
	return 0;
}
