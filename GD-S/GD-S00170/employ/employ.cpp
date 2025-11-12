#include<cstdio>

#include<algorithm>

constexpr int mod=998244353;
using i64=long long;

constexpr int maxn=5e2+9;

int s[maxn],c[maxn],p[maxn];

//8pt
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	int N,M;scanf("%d%d",&N,&M);
	
	for(int i=0;i<N;i++)
		scanf("%1d",s+i);
	
	for(int i=0;i<N;i++)
		scanf("%d",c+i);
		
	int sum=0;
	for(int i=0;i<N;i++)
		sum+=s[i];
	if(sum<M){
		putchar('0');
		return 0;
	}

	for(int i=0;i<N;i++)
		p[i]=i;
	
	i64 ans=0;
	do{
		int dis=0;
		
		for(int i=0;i<N;i++)
			if(!s[i]||c[p[i]]<=dis)
				dis++;
		
		if(dis+M<=N) ans++;
	}while(std::next_permutation(p,p+N));
	
	printf("%lld",ans%mod);
	
	return 0;
}
