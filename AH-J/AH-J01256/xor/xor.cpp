#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[500005];
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	bool f=0;
	cin>>n>>k;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			f=1;
		}
	}
	if(f==0){
		if(k==0&&a[1]!=0) cout<<n/2;
		else if(k==0&&a[1]==0) cout<<n;
		else if(k!=0&&a[1]==0) cout<<0;
		else if(k!=0&&a[1]!=0){
			if(k==a[1]) cout<<n;
			else cout<<0;
		}
	}else{
		ll cnt=0;
		for(ll l=1;l<=n;l++){
			for(ll r=l;r<=n;r++){
				bool ok=0;
				for(int i=l;i<=r;i++){
					if(vis[i]) ok=1;
				}
				if(ok==0){
					ll cum=a[l];
					for(ll i=l+1;i<=r;i++){
						cum^=a[i];
					}
					if(cum==k){
						for(int i=l;i<=r;i++){
							vis[i]=1;
						}
						cnt++;
					}
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}

