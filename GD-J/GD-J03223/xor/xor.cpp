#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
const ll N=5e5+10;
using namespace std;
ll n,k,ans,t;
int a[N],b[N],s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		ans+=a[i];
	}
	if(k==1) cout<<ans;
	else if(k==0){
		ans=n-ans;
		for(ll i=2;i<=n;++i){
			if(a[i]==a[i-1] && a[i]!=0){
				ans++;
				a[i]=0;
			}
		}
		cout<<ans;
	}
	else if(k<=255){
		ans=0,t=1;
		for(ll i=1;i<=n;++i){
			if(a[i]==k){
				ans++;
				a[i]=-1;
				break;
			}
			if(log2(a[i])==log2(k)){
				b[i]=k^a[i];
				for(ll j=t;j<=i;++j){
					if(b[i]^s[i-1]^s[j]==0) {
						ans++;
						t=i+1;
						break;
					}
				}
			}
		}
		cout<<ans; 
	}
	else cout<<"0";
	return 0;
} 
//RP++
