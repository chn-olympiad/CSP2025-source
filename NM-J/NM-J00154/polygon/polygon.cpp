#include<bits/stdc++.h>
using namespace std;
bool com(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int ans=0;
	cin>>n;
	int wood[n];
	for(int i=0;i<n;i++)
	{
		cin>>wood[i];
	}
	sort(wood,wood+n,com);
	queue<int> A;
	for(int i=0;i<=pow(2,n);i++)
	{
		int a=i;
		while(a!=0)
		{
			if(a%2==0)
			{
				A.push(0);
				a/=2;
			}
			if(a%2==1)
			{
				A.push(1);
				a=(a-1)/2;
			}
		}
		int totalwood=0;
		int ie=0;
		int maxwood=0;
		for(int j=0;j<n;j++)
		{
			if(A.empty())
			{
				break;
			}
			else
			{
				if(A.front()==1)
				{
					if(ie==0)
					{
						maxwood=2*wood[j];
					}
					totalwood+=wood[j];
					ie++;
				}
			}
			A.pop();
		}
		if(totalwood>maxwood and ie>=3)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
