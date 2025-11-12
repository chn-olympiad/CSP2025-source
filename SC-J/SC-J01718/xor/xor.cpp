#include<bits/stdc++.h>
using namespace std;
int a[500005],pre[500005];
int n,k;
void solve(){
	map<int,int>mp;
	mp[0]=1;
	int cnt=0,l=1;
	for(int i=1;i<=n;i++){
		if(mp[pre[i]^k]==1){
			cnt++;
			mp.clear();
		}mp[pre[i]]=1;
	}cout<<cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	solve();
	return 0;
}
