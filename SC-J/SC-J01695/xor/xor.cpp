#include<bits/stdc++.h>
#define int long long
using namespace std;
int mp[2100000];
int pre[500010];
int a[500010];
int n,k,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	mp[0]++;
	int ptr=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
//		cout<<ptr<<endl;
		if(mp[pre[i]^k]!=0){
//			cout<<i<<" "<<mp[0]<<endl;
			ans++;
			while(ptr<i){
				mp[pre[ptr]]--;
				ptr++;
			}
		}
		mp[pre[i]]++;
	}
	cout<<ans;
	return 0;
}