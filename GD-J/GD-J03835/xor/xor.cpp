#include<iostream>
#include<algorithm>
using namespace std;
long long n,k;
long long f[500015],a[500015],cnt,ans;
struct hjj
{
 long long l,r;	
};
hjj num[500015];
bool cmp(hjj x,hjj y)
{
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		long long huo=0;
		for(int j=i;j<=n;j++)
		{
			huo=huo^a[j];
			if(huo==k)
			{
				num[++cnt].l=i;
				num[cnt].r=j;
				break;
			}
		}
	}
	sort(num+1,num+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		f[i]=f[i-1];
		for(int j=0;j<i;j++)
		{
			if(num[j].r<num[i].l)f[i]=max(f[i],f[j]+1);
		}
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<ans;
}

