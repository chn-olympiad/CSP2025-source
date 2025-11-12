#include <bits/stdc++.h>
using namespace std;
int a[5010];
int cnts[5010];
int modn=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	int m5k=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=5000;j++) 
		{
			ans+=cnts[j];
			ans%=modn;
		}
		ans+=m5k;
		ans%=modn;
		m5k+=m5k;
		m5k%=modn;
		for(int j=5000;j>=1;j--)
		{
			if(j+a[i]<=5000) 
			{
				cnts[j+a[i]]+=cnts[j];
				cnts[j+a[i]]%=modn;
			}
			else 
			{
				m5k+=cnts[j];
				m5k%=modn;
			}
		}
		cnts[a[i]]++;
		cnts[a[i]]%=modn;
	}
	cout<<ans;
}
