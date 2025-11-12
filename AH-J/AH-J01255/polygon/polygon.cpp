#include<bits/stdc++.h>
using namespace std;
int n,a[1006],tot=0;
int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]+a[k]>max(a[i],max(a[j],a[k])));
				tot++;
			}
		}
	}
	cout<<tot;
	return 0;
}
