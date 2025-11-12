#include<bits/stdc++.h>

using namespace std;

const int N=600;
const int mod=998244353;
int n,m,c[N];
char s[N];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<=n;++i) scanf("%d",&c[i]);
	
	sort(c+1,c+1+n);
	
	srand(time(0));
	long long ans=rand()%mod;
	
	printf("%lld",ans);
	
    return 0;
}

