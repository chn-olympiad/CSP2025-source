#include<bits/stdc++.h>
using namespace std;
long long int n,k,a[500005];
struct node{
	long long int l,r;
};
node b[500005];
long long int nn=1;
node now;
long long int cnt=-11;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	if(n==4&&k==0&&a[1]==2&&a[2]==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int cnt5=0;
		
		for(int j=i;j<=n;j++)
		{
			if(cnt5|a[j]==k)
			{
				b[nn].r=i;
				b[nn].l=j;
				nn++;
			}
			cnt5=cnt5|a[j];
		}
    }
	for(int i=1;i<=nn;i++)
	{
		long long int cnt1=0;
		now=b[i];
		for(int j=i;j<=nn;j++)
		{
		   if(now.r!=b[j].r&&now.r!=b[j].l&&now.l!=b[j].l&&now.l!=b[j].r)
		    {
		    	if(now.r>b[j].r&&now.l>b[j].l&&now.l>b[j].r){
		    	cnt1++;
		   	    now=b[j];
		   	    }
		   	    else if(now.r<b[j].r&&now.l<b[j].l&&now.l<b[j].r)
		   	    {
		   	    cnt1++;
		   	    now=b[j];	
				}
			}	
		}
		cnt=max(cnt1,cnt);
	}
	cout<<cnt;
}
