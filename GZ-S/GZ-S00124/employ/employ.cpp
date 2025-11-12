//GZ-S00124 贵阳市白云区华师一学校 姜裕伟
#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505];
int ss;
long long ans=1;
int aaa(int x)
{
	int l=1,r=n,ans=-1;
	while(l<=r)
	{
		int m=(l+r)/2;
		if(a[m]<=x)
		{
			l=m+1;
			ans=m;
		}
		else 
		{
			r=m-1;
		}
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int nn=n;
	for(int i=1;i<=n;i++) if(a[i]==0) nn--;
	for(int i=0;i<nn;i++)
	{
		ans*=(i+1);
		ans%=998244353;
	} 
	printf("%lld",ans);
	return 0;
}

