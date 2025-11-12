#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,MOD=998244353;
int n,m,c[N],fz=0,id[N],ans=0;
char s[N];
signed main() {
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool fo=1;
	for(int i=1; i<=n; i++)cin>>s[i],fo&=(s[i]=='1');
	for(int i=1; i<=n; i++)cin>>c[i],fz+=(c[i]!=0);
	for(int i=1; i<=n; i++)id[i]=i;
	if(n<=10) {
		do {
			int cnt=0,res=0;
			for(int i=1; i<=n; i++) {
				if(cnt<c[id[i]]) {
					if(s[i]=='0')cnt++;
					else res++;
				} else cnt++;
			}
			if(res>=m)ans++,ans%=MOD;
		} while(next_permutation(id+1,id+n+1));
		cout<<ans<<"\n";
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n;i++)if(s[i]!='1')return cout<<"0\n",0;
		cout<<"1\n";
		return 0;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
