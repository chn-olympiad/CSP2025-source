#include<bits/stdc++.h> 
using namespace std;
int Max(int L[],int n)
{
	int count = 0;
	for(int i = 3;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			int Max = 0;
			int Mx;
			for(int w = 0;w<i;w++)
			{
				Mx += L[j - w];
				Max = max(Max,L[j-w]);
			}
			if(Mx>Max*2)
			{
				count = count+1;
				int NMX = Mx;
				for(int w = 2;w<i+1;w++)
				{
					NMX += L[j - w];
				}
				if(NMX>Max*2) count = count + 1;
			}
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int L[n+1];
	for(int i = 1;i<=n;i++)
	{
		cin>>L[i];
	}
	sort(L+1,L+n+1);
	int Count = Max(L,n);
	cout<<Count + 3;
	fclose(stdin);
	fclose(stdout);
}
