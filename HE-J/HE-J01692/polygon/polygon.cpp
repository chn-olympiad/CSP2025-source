#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e3+10;
const int mod = 998244353;
int n,a[maxn],maxx=INT_MIN,sum,cnt;
long long ans;
int main() 
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int i=0,j=0;
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);

	for (int i=1; i<=n; i++) 
	{
		for (int j=i; j<=n; j++) 
		{
			cnt++;
			sum+=a[j];
			if (cnt>=3 && sum!=0) 
			{
				int m=INT_MIN;
				m=max(m,a[j]);
				if (sum>m*2)
				{
					ans++;
				}
					
			}
		}
		//i++;
		sum=0;
	}
	cout<<ans%mod;
	return 0;
}

