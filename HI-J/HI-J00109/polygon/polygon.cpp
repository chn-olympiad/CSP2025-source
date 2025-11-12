#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=0;
	for(int i=3;i<=n;i++)
	{
		bool y=true;
		while(y)
		{
			for(int p=n+1;p>=i;p--)
			{
				int ans=0;
				for(int j=1;j<=n;j++)
				{
					ans+=a[p]+a[p-j];
				}
				if(ans>a[1]*2)
				{
					for(int k=1;k<=p;k++)
					{
						cnt+=k;
					}
					break;
				}
			}
			y=false;
		}
	}
	cout<<cnt/7;
	return 0;
}

