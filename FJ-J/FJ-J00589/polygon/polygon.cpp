#include <bits/stdc++.h>
using namespace std;
int n;
int ans=1;
int a[500005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int he=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		he+=a[i];
	}
	for(int k=1;k<=n;k++)//当前枚举的木棍
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sort(a+1,a+n+1);
			for(int j=i+1;j<=i+k;j++)
			{
				if(j-i<3 || a[n+1]*2>=he)
					continue;
				ans++;
			}
		}
	}
	
	cout<<ans%998244353;
	return 0;
}
