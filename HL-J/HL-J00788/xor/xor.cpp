#include<bits/stdc++.h>
using namespace std;
int a[50000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int t=1;
	int s=1;
	int tnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			t=0;
		}
		if(a[i]!=1||a[i]!=0)
		{
			s=0;
		}
		if(a[i]==1)
		{
			tnt++;
		}
	}
	if(t==1&&k==0)
	{
		if(n%2==1)
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
		
	}
	else if(s==0&&(k==0||k==1))
	{
		
		if(k==0)
		{
			if(tnt%2==1)
			{
				cout<<0;
			}
			else
			{
				cout<<1;
			}
		}
		else
		{
			if(tnt%2==1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

