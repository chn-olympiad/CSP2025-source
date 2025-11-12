#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 5e3;
string s1[N],s2[N];int hat1[N],hat2[N],pw[N];map<pair<int,int>,int>mp; int n,q;
int get1(int l,int r){
	return (hat1[r]-hat1[l-1]*pw[r-l+1]%mod+mod)%mod;
}
int get2(int l,int r){
	return (hat2[r]-hat2[l-1]*pw[r-l+1]%mod+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;pw[0] = 1;
	for(int i = 1;i<=5000;i++) pw[i] = pw[i-1]*300%mod;
	for(int i = 1;i<=n;i++){
		cin>>s1[i]>>s2[i];int m = s1[i].size();
		s1[i] = ' '+s1[i],s2[i] = ' '+s2[i];int k1 = 0,k2 = 0;
		for(int j = 1;j<=m;j++) k1 = (k1*300%mod+s1[i][j])%mod;
		for(int j = 1;j<=m;j++) k2 = (k2*300%mod+s2[i][j])%mod;
		mp[{k1,k2}]++;
	}
	while(q--){
		int ans = 0;
		string t1,t2;cin>>t1>>t2;int m = t1.size();t1 = ' '+t1,t2 = ' '+t2;
		for(int i = 1;i<=m;i++){
			hat1[i] = (hat1[i-1]*300+t1[i])%mod;
			hat2[i] = (hat2[i-1]*300+t2[i])%mod;
		}
		for(int i = 1;i<=m;i++){
			bool flag = 0;
			for(int j = 1;j<i;j++) if(t1[j]!=t2[j]) flag = 1;
			if(flag) continue;
			for(int j = i;j<=m;j++){
				bool flag = 0;
				for(int h = j+1;j<=m;j++) if(t1[h]!=t2[h]) flag = 1;
				if(flag) continue;
				int k = get1(i,j);
				int k2 = get2(i,j);
				ans += mp[{k,k2}];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
