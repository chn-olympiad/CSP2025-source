#include <bits/stdc++.h>
using namespace std;
bool f11=1,f10=1;
using ll=long long;
ll n,a[500005],k;
void solve1(){
	if(k==1) {
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}
	else if(k==0){
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			else if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
}
int main(){
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f11=0;
		if(!(a[i]==0 ||a[i]==1)) f10=0;
	}
	if(k==0&&f11) cout<<n/2;
	else if(f10) solve1();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
