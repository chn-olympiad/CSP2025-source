#include<bits/stdc++.h>
using namespace std;
const int N=5e2+9;
const long long MOD=998244353;
int n,m;char s;
int tag[N],p[N],c[N];
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s,tag[i]=s-'0';
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	do{
		int tot=0;
		for(int i=1;i<=n;i++){
			int u=p[i],o=(i-1)-tot;
			if(tag[i]==0||o>=c[u]) continue;
			else tot++;
		}
		if(tot>=m) ans++,ans%=MOD;
	}while(next_permutation(p+1,p+1+n));
	printf("%lld\n",ans);
	return 0;
} 