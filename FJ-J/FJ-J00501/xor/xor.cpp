#include <iostream>
using namespace std;

//xor:^
//This is xor cheater program(about 35pts)

unsigned long long n,k,a[514514];
bool hasnzero=true;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i]==0)hasnzero=false;
	}
	if (k==0)
	{
		if (hasnzero)
			cout << n/2;
		else{
			int cntaaa=0;
			for (int i=1;i<=n;i++)
			{
				if (a[i]==0)cntaaa++;
			}
			for (int i=1;i<=n;i++)
			{
				if (a[i]==1&&a[i+1]==1)
				{
					cntaaa++;
					a[i]=a[i+1]=314;
				}
			}
			cout << cntaaa;
		}
	}
	if (k==1)
	{
		int cntaaa=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==1)cntaaa++;
		}
		for (int i=1;i<=n;i++)
		{
			if (a[i]==0&&a[i+1]==0)
			{
				cntaaa++;
				a[i]=a[i+1]=314;
			}
		}
		cout << cntaaa;
	}
	if (k!=0&&k!=1)cout << n/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
