#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef long long ll;
ll n,k,a[N],sum=0,e=-1;
bool st[N];

void solve(){
	cin >> n >> k;
	for(ll i=1;i<=n;i++) cin >> a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			bool f=1;
			for(ll l=j;l<j+i;l++){
				if(st[l]){
					f=0;
					break;
				}
				if(e==-1) e=a[l];
				else e=e^a[l];
			}
			if(e==k&&f){
				sum++;
				for(ll l=j;l<j+i;l++) st[l]=1;
			}
			e=-1;
		}
	}
	cout << sum << '\n';
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}