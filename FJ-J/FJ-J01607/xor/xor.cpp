#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n,k,s,ans;
map<int,int> m;
void solve(){
	cin>>n>>k;
	if(k==0){
		for(int i=1,x;i<=n;i++){
			cin>>x;
			if(x==0)ans++;
		}
		cout<<ans;
		return;
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		s=s^x;
		m[s]++;
		if(s==k){
			ans++;
			s=0;
			m.clear();
		}else if(m[s^k]>0){
			ans++;
			s=0;
			m.clear();
		}
	}
	cout<<ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num=1;
	//cin>>num;
	while(num--)solve();
	return 0;
}
