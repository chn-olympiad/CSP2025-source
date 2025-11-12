#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,m,c[100];
char s[100];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>(s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n>11)
	{
		cout<<"0";
		return 0;
	}
	int a[100];
	long long cnt=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		cnt*=i;
		a[i]=i;
	}
	while(cnt--)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
//			cout<<a[i];
			if(s[i]=='0'||t>=c[a[i]]) t++;
		}
//		cout<<t;
		if(n-t>=m) ans++;
		next_permutation(a+1,a+1+n);
	}
	printf("%lld",ans);
	return 0;
}