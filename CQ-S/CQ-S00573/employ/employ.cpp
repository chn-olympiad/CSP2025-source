#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e2+10,mod=998244353;
int a[maxn],c[maxn],s[maxn];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;cin>>ch;
		a[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)s[i]=i;
	int ans=0;do{
		int res=0,sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]&&c[s[i]]>sum)res++;
			else sum++;
		}
		ans=(ans+(res>=m))%mod;
	}while(next_permutation(s+1,s+n+1));
	cout<<ans;
	return 0;
}
//$O(n!)$, terrible.
