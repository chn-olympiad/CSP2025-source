#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int vis1=0,vis2=0;
int ling1=0,ling2=0;
int x=0,z=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			ling1++;
			ling2++;
		}
		if(a[i]==1)
		{
			x++;
			z++;
		}
		if(a[i]!=1)
		{
			vis1=1;
		}
		if(a[i]!=1 && a[i]!=0)
		{
			vis2=1;
		}
	}
	if(vis1==0)
	{
		cout<<n/2;
		return 0;
	}
	if(vis2==0)
	{
		if(k==0)
		{
			int cnt1=0,cnt2=0;
			for(int l=1,r=2;r<=n;l+=2,r+=2)
			{
				if(a[l]==0 && a[r]==0)
				{
					cnt1++;
					ling1-=2;
				}
				if(a[l]==1 && a[r]==1)
				{
					cnt1++;
				}
			}
			cnt1+=ling1;
			for(int l=2,r=3;r<=n;l+=2,r+=2)
			{
				if(a[l]==0 && a[r]==0)
				{
					cnt2++;
					ling2-=2;
				}
				if(a[l]==1 && a[r]==1)
				{
					cnt2++;
				}
			}
			cnt2+=ling2;
			cout<<max(cnt1,cnt2);	
		}
		else if(k==1)
		{
			int cnt3=0,cnt4=0;
			for(int l=1,r=2;r<=n;l+=2,r+=2)
			{
				if(a[l]==0 && a[r]==1)
				{
					cnt3++;
					x--;
				}
				if(a[l]==1 && a[r]==0)
				{
					cnt3++;
					x--;
				}
			}
			cnt3+=x;
			for(int l=2,r=3;r<=n;l+=2,r+=2)
			{
				if(a[l]==0 && a[r]==1)
				{
					cnt4++;
					z--;
				}
				if(a[l]==1 && a[r]==0)
				{
					cnt4++;
					z--;
				}
			}
			cnt4+=z;
			cout<<max(cnt3,cnt4);	
		}
	}
	return 0;
}
/*
11 0
0 0 0 1 1 0 0 1 1 0 0

100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
*/
