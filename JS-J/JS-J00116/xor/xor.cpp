#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1005],aq[1005][1005],maxn=0;
vector <int> b[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	
	if (k==1)
	{
		int sd=0;
		for (int i=1;i<=n;i++)
		{
			
			cin >> a[i];
			if (a[i]==1)
			{
				sd++;
				maxn=max(maxn,sd);
			}
			else
			{
				sd=0;
			}
		}
	}
	if (k==0)
	{
		for (int i=1;i<=n;i++)
		{
			cin >> a[i];
			if (a[i]==0)
			{
				maxn=n;
			}
		}
		cout << maxn;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		int n=a[i];
		while(n)
		{
			b[n].push_back(n%2);
			n/=2;
		}
	}
	cout << maxn;
	return 0;
}
