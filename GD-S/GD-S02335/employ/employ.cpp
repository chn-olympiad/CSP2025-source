//
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,MAXN=505;

int s[MAXN],c[MAXN],pre[MAXN],id[MAXN];
vector<int> num;
int siz=0;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%lld %lld",&n,&m);
	getchar();
	for (int i=1;i<=n;i++){
		char c;
		c=getchar();
		s[i]=c-'0';
		if (!s[i]) id[++siz]=i;
		pre[i]=pre[i-1]+s[i];
	}
	for (int i=siz+1;i<=n+4;i++) id[i]=n+1;
	for (int i=1;i<=n;i++) scanf("%lld",&c[i]);
	if (pre[n]==n){
		int mul=1;
		for (int i=1;i<=n;i++)
			mul=(mul*i)%mod;
		printf("%lld",mul);
		return 0;
	}
	if (n<=10){
		vector<int> v;
		for (int i=1;i<=n;i++) v.push_back(i);
		int ans=0;
		do{
			int sum=0,sum1=0;
			for (int i=0;i<n;i++){
				if (sum>=c[v[i]] or !s[i+1]){
					sum++;
					continue;
				}
				sum1++;
			}
			if (sum1>=m) ans++;
		}
		while (next_permutation(v.begin(),v.end()));
		printf("%lld",ans);
	}
	if (m==n){
		num.clear();
		for (int i=1;i<=n;i++)
			num.push_back(id[c[i]+1]-1);
		sort(num.begin(),num.end());
		int mul=1;
		for (int i=0;i<num.size();i++)
			mul=(mul*max(0ll,(num[i]-i)))%mod;
		printf("%lld",mul);
		return 0;
	}

	return 0;
}
/*froepen*/
/*uid:1774140.*/
/*
only 232 pts.no no no no no no no no no no no no no plssssssssssssssssssssss oh my god.
尽力了。。。
不过相比去年好了些。至少没有前两题花3h甚至更多。这回只花了1h就切了。 
*/
/**/ 
