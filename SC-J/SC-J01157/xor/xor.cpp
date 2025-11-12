#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans;
bool check(int l,int r){
	int now=a[r];
	if(now==k)return true;
	for(int i=r-1;i>=l;i--){
		now=now^a[i];
		if(now==k)return true;
	}
	return false;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=1;
	while(r<=n){
		if(check(l,r)==true){
			ans++;
			r++;
			l=r;
		}
		else r++;
	}
	cout<<ans;
	return 0;
}