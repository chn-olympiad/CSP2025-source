#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s,ans;
bool b[500005],f;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int t=1;t<=n;t++)
	{
		for(int i=1;i<=n-t+1;i++)
		{
			f=0;
			s=a[i];
			for(int j=i+1;j<=i+t-1;j++)
			{
				if(b[j]){f=1;break;}
				s^=a[j];
			}
			if(!f&&s==k)
			{
				ans++;
				for(int j=i;j<=i+t-1;j++) b[j]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
