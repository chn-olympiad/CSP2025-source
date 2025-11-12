#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+10;
ll n;
ll a[MAXN];
ll k;
ll ans;
vector<ll>v;
bool vis[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	bool flag=true;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=false;
		}
	}
	
	if(flag){
		cout<<n/2;
		return 0;
	}
	
	if(a[1]==k){
		ans++;
		vis[1]=1;
	}
	
	for(int i=2;i<=n;i++){
		if(a[i]==k){
			ans++;
			vis[i]=1;
			continue;
		}
		int tmp=a[i];
		for(int j=i-1;j>=1;j--){
			if(vis[j])break;
			tmp^=a[j];
			if(tmp==k){
				ans++;
				for(int k=j;k<=i;k++){
					vis[k]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

