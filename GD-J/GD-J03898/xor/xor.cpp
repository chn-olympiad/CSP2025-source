#include <bits/stdc++.h>
using namespace std;

long long k,num[500005];
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,l,r,cnt=0,a=1,yi=0,cnt2=0;
	int cnum[260]={0};
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> num[i];
	}
	
	if (k==0)
	{
		if(n==2)
		{
			cout<< 1;
			return 0;
		}
		else if (n==1)
		{
			cout << 0;
			return 0;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if (num[i]==k) 
		{
			cnt++;
			cnum[n]+=1;
		}
	} 
	
	for(int i=1;i<n-1;i++)
	{
		for(int j=i;j<=n;j++)
		{
			yi = (yi^num[j]);
			//cout << yi << endl;
			if(yi==k)
			{
				for(int z=1;z<=j;z++)
				{
					//cout << z << " " << cnum[num[z]];
					if(cnum[num[z]]==0)
					{
						cnt2++;
					}
				}
				
				if(cnt2==j) 
				{
					//cout << " " << j << " " << cnt;
					cnt++;
					for(int z=1;z<=j;z++)
					{
						cnum[z]++;
						cnt2 = 0;
					}
				}
			}
		}
		a++;
		yi = 0;
	}
	cout << cnt;
	return 0;
}
