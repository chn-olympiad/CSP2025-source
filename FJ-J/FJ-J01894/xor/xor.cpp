#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500005];
bool b[500005];

void solve(){
	ll n,k;
	cin>>n>>k;
	if(n==1){
		cout<<0;
		return ;
	}
	if(n==2){
		cout<<1;
		return ;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			b[i]=1;
		}
	}
	for(int l=1;l<=n;l++){
		if(b[l]) continue;
		int sum=a[l];
		for(int r=l+1;r<=n;r++){
			if(b[r]){
				break;
			}else{
				sum=sum^a[r];
				if(sum==k){
					ans++;
					l=r+1;
					break;
				}
			}
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	return 0;
}//awa

