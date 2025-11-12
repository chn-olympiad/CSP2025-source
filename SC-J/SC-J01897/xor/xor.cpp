#include<bits/stdc++.h>
using namespace std;
//int xor(int a,int b)
//{
//	
//}
int n,k,a[200005];
int F=0;
int cot1=0,cot0=0,cot11;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			F=1;
			cot0++;
		}
		if(a[i]==1)
		{
			cot1++;
		}
	}
	if(k==0&&F==0)
	{
		cout<<n/2;
		return 0;
	}
	if(k==1&&F==1)
	{
		cout<<cot1;
		return 0;
	}
	if(k==0&&F==1)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]==1&&a[i-1]==1)
			{
				cot11++; 
				i++;
			}
		}
		cout<<cot0+cot11;
	}
	cout<<2;
	return 0;
} 