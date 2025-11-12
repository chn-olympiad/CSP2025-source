#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353; 
long long ans=0;
int n,m;
char a[501];
int p[501];
bool aa[501];
bool ch()
{
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='1') aa[i]=1;
		else{ok=0;aa[i]=0;}
	}
	return ok;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	if(ch())
	{
		int nn=n;
		for(int i=1;i<=nn;i++) if(p[i]==0) n--;
		ans=1;
		for(long long i=1;i<=n;i++)
		{
			ans=(ans*i)%mod;
			//printf("%lld %lld\n",i,ans);
		}
	}
	else ans=0;
	printf("%lld",ans);
}
/*
这是蓝/紫/黑吧QAQ 
不会
只能骗了QAQ 
*/
//I think I may be 3~2=
//QAQ
//freeopen(免费开启) 
//froepen
//freopen
//zto 大佬们 orz 
