#include<iostream>
using namespace std;
long long n,m;
long long ans;
long long c[600],a[600];
bool flag[600];
string s;
void dfs(long long depth){
	if (depth>n){
		long long t=0;
		for (long long i=1;i<=n;i++)
			if (s[i-1]=='0'||t>=c[a[i]])
				t++;
		if ((n-t)>=m)
			ans=(ans+1)%998244353;
		return ;
	}
	for (long long i=1;i<=n;i++)
		if (flag[i]==0){
			flag[i]=1;
			a[depth]=i;
			dfs(depth+1);
			flag[i]=0;
			a[depth]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	bool q=1;
	for (long long i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for (long long i=0;i<s.size();i++)
		if (s[i]=='1')
			q=false;
	if (q){
		printf("0");
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
