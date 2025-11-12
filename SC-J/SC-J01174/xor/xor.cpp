#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll n,k;
ll a[N];
bool flg1 = 1,flg2 = 1;
ll ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] != 1) flg1 = 0;
		if(a[i] > 1) flg2 = 0;
	}
	if(flg1){
		if(k > 1) cout<<0<<endl;
		else if(k == 1) cout<<n<<endl;
		else cout<<n/2<<endl;
	}
	else if(flg2){
		if(k > 1) cout<<0<<endl;
		else if(k == 1){
			for(int i = 1;i <= n;i++){
				if(a[i]) ans++;
			}
			cout<<ans<<endl;
		}
		else{
			for(int i = 1;i <= n;i++){
				if(!a[i]) ans++;
				else if(a[i+1] == 1){
					ans++;
					i++;
				}
			}
			cout<<ans<<endl;
		}
	}
	else{
		for(int i = 1;i <= n;i++) if(a[i] == k) ans++;
		cout<<ans<<endl;
	}
	return 0;
}