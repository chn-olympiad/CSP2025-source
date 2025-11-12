#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],ans,a[501];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int sum=0,f=0;
			for(int k=1;k<=n;k++)
			{
				if(a[k]) continue;
				if(s[k-1]=='1') sum++;
				else
				{
					f++;
					a[k]=1;
					for(int pos=k;pos<=n;pos++)
					{
						if(f>=c[pos])
						{
							f++;
							a[pos]=1;
						}
					}
				}
			}
			if(sum>=m) ans++;
			memset(a,0,sizeof(a));
			swap(c[i],c[j]);
		}
	}
	cout<<ans;
}
