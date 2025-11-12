#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int s[5000+10],n;
int alln=0,res=0,ans=0;
const int modn=998244353;
void dfs(int stt)
{
	if(alln>2*s[stt])
	{
		res++;
		res%=modn;
	}
	for(int i=stt+1;i<=n;i++)
	{
		alln+=s[i];
		dfs(i);
		alln-=s[i];
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	sort(s+1,s+n+1);
	dfs(0);
	cout<<res;
	return 0;
}

