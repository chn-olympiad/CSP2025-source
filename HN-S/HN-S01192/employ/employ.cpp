#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int mod=998244353;
int a[1000000],p[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	string s;
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=i;
	}
	int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt>=a[p[i]]) cnt++;
		}
		if(cnt<=n-m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<'\n';
	return 0;
}