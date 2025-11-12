#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<int>v(n),c(n);
	for(int i=0;i<n;i++)
		cin>>c[i];
	for(int i=0;i<n;i++)
		v[i]=i;
	ll ans=0;
	do{
		int cnt=0,suc=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'||cnt>=c[v[i]]){
				++cnt;
			}else{
				++suc;
			}
		}
		if(suc>=m)
			++ans;
	}while(next_permutation(v.begin(),v.end()));
	cout<<ans%mod<<'\n';
	return 0;
}