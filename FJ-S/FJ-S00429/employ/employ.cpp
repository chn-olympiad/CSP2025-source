#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
#define T(x,y) x=(x+(y))%mod
#define S(x,y) (1ll*(x)*(y)%mod)
int n,m,a[N],p[N];
char s[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	int num=0;
	for(int i=1;i<=n;i++) num+=s[i]=='0';
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	if(n>10&&m==n)
	{
		if(num<n){puts("0");return 0;}
		for(int i=1;i<=n;i++)
			if(!a[i]){puts("0");return 0;}
		int res=1;
		for(int i=1;i<=n;i++) res=S(res,i);
		printf("%d\n",res);
	}
	else
	{
		int res=0;
		for(int i=1;i<=n;i++) p[i]=i;
		do
		{
			int now=0,num=0;
			for(int i=1;i<=n;i++)
				if(s[i]=='0') now++;
				else if(now>=a[p[i]]) now++;
				else num++;
			res+=num>=m;
		}while(next_permutation(p+1,p+n+1));
		printf("%d\n",res);
	}
	return 0;
}
