#include <bits/stdc++.h>
using namespace std;
long long n,a[100050][10],b[100050][10],cnt2 = 0,maxn = 0;
long long maxx[1000050];
int main()
{
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		for(int j=1;j<=t;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin >> a[j][k];
			}
		}
		for(int j=1;j<=t;j++)
		{
			for(int k=1;k<=3;k++)
			{
				b[j][k] = 0;
				if(b[j][k-1] = 1)
				{
					continue;
				}
				else{
					maxx[j]+=a[j][k];
					b[j][k] = 1;
					cnt2+=1;
					if(maxx[j] > maxx[j-1])
					{
						maxn = maxx[j];
			    	}
				}
				if(cnt2 > n/2)
				{
					continue;
				}
			}
		}
		cout << maxx;
	}
	
	return 0;
} 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
