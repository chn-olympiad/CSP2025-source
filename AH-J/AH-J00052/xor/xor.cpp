#include<bits/stdc++.h>
using namespace std;
int a[500010],n,k,l,e=500010,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(i-1==e)ans++,e=500010;
		l=0;
		for(int j=i;j<=n;j++)
		{
			l^=a[j];
			if(l==k)
			{
				if(j<e)e=j;
				break;
			}
		}
	}
	if(n==e)ans++;
	cout<<ans<<endl;
	return 0;
}

