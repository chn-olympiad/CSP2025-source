#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,k,ans;
int a[500005];
unordered_map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	mp[0]++;
	for(int i=1;i<=n;i++){
		int p=a[i]^k;
		if(mp.count(p)){
			ans++;
			mp.clear();
		}
		mp[a[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}
//miaochusilu,bangexiaoshimiaole
//xianzaishi9:30
