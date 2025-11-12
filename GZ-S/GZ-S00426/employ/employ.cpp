//GZ-S00426 遵义市第四中学 赵振宇
#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long ans=1;
int n,m,idx,cnt;
string s;
int a[501];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(m==n)
	{
		//sort(a+1,a+n+1,cmp);
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='0')
			{
				cout<<0;
				return 0;
			}
		}	
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		printf("%lld",ans%mod);
	}	
	return 0;
}

