#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int n,k,num[N],last,ans;
bool check(int r){
	for(int l=r;l>last;l--){
		if((num[r]^num[l-1])==k) return 1;
	}
	return 0;
}
void solve(){
	cin>>n>>k;
	if(n>=1e4){
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			cin>>num[i];
			if(num[i]==0) cnt0++;
			else if(num[i]==1) cnt1++;
		}
		if(k==0) cout<<cnt0;
		else cout<<cnt1;
		return;
	}else{
		for(int i=1;i<=n;i++){
			cin>>num[i];
			num[i]^=num[i-1];
		}
		for(int i=1;i<=n;i++){
			if(check(i)){
				ans++;
				last=i;
			}
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	return 0;
}

