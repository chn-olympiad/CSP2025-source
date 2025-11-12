#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=998244353;
int n,m,c[N],a[N];
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=0; i<n; i++)cin>>c[i];
	for(int i=0; i<n; i++)a[i]=i;
	ll ans=0;
	do {
		int cnt=0;
		for(int i=0; i<n; i++) {
			if(s[i]=='1'&&(i-cnt<c[a[i]]))cnt++;
			//cout<<a[i]<<' ';
		}//cout<<'\n'<<cnt<<'\n';
		if(cnt>=m)ans=(ans+1)%M;
	} while(next_permutation(a,a+n));
	cout<<ans<<'\n';
	return 0;
}

