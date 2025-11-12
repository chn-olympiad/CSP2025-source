#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int P=21;

int a[N];


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	
	int n,k;
	cin>>n>>k;
	
	int bj=1;
	int c=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)bj=0;
		if(a[i]==0)c=1;
	}
	if(bj)
	{
		int ans=0;
		if(c==1)
		{
			int bj=0;
			for(int i=1;i<=n;i++)
			{
				if(bj==1)
				{
					bj=0;
					continue;
				}
				if(k==0)
				{
					if(a[i]==k)ans++;
					else if(a[i]==1&&a[i+1]==1)
					{
						ans++;
						bj=1;
					 }
				}
				else if(k==1) 
				{
					if(a[i]==k)ans++;
				}
			}
		}
		
		else 
		{
			if(k==0)ans=n/2;
		}
		cout<<ans;
		return 0;
	}
	else cout<<0;
	
	return 0;
 } 
 // 4 3 2 1 0 3