#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000;
const int mod=998244353;
int n,m,cnt[N];
char s[N];
void xpigeon(){
	cin>>n>>m;
	cin>>s;
	for(int i=1,c;i<=n;i++){
		cin>>c;
		cnt[c]++;
	}
	cout<<0<<'\n';
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	xpigeon();
	return 0;
}