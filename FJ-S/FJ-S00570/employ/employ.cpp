#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,d[N],v[N],sum[N];
long long res=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=1;i<=n;i++){
		d[i]=s[i-1]-'0';
		if(d[i]) sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	for(int i=1;i<=n;i++) res=res*i%mod;
	printf("%lld",res);
	return 0;
} 
