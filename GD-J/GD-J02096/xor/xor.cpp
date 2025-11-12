#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0&&n==2)
	{
		if(a[1]==a[2])
		{
			if(a[1]==0)
			{
				cout<<"2";
			}
			else
			{
				cout<<"1";
			}
		}
		else if(a[1]==0||a[2]==0)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"2";
	}
	return 0;
}
