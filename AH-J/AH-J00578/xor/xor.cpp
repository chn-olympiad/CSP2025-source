#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int sum[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	int la=0;
	int ans=0;
	int x;
	//int lll=0;
	for(int i = 1;i<=n;i++)
	{
		cin >> x;
		sum[i]=sum[i-1]^x;
		for(int j=i;j>la;j--)
		{
			//sum^=x;
			//lll++;
			//if(j<=la) break;
			if((sum[i]^sum[j-1])==k)
			{
				ans++;
				la=i;
				break;
			}
		}
	}
	
	/*
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j>=1;j--)
		{
			if(j<=la) break;
			if((sum[i]^sum[j-1]) == k)
			{
				//cout << "j=" << j << " i=" << i << "\n";
				ans++;
				la=i;
				break;
			}
		}
	}
	*/
	//cout << "lll=" << lll << "\n";
	cout << ans;
	return 0;
}
