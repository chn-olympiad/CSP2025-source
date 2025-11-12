#include<bits/stdc++.h>
#define int long long
const int kMaxN=505;
const int MOD=998244353;
using namespace std;
int n,m;
string s;
int a[kMaxN];
int p[kMaxN];
int vis[kMaxN];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]==1){
				cnt++;
			}
		}
		cout<<(cnt*n)%MOD;
		return 0;
	}
	return 0;
}
/*
*/
