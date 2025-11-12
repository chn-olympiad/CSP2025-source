#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=505,mod=998244353,inf=0x3f3f3f3f;
int n,m,c[MAXN],p[MAXN],ans=0;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m>>s;
	s='\0'+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
	}
	do{
		int now=0;
		for(int i=1;i<=n;i++){
			if(now>=c[p[i]]){
				++now;
				continue;
			}
			now+=(s[i]^'1');
		}
		(ans+=(n-now>=m))%=mod;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}

