#include<bits/stdc++.h>
using namespace std;
int n,k,a[600002];
int book[1000203];
int boook[1000002];
int c[100002],d[1000002];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		book[a[i]]++;
		boook[i]=a[i];
	}
	if(book[1]==n)
	{
		cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(book[i]>0)
			cnt++;
	if(cnt==2 && book[1]+book[0]==n)
	{
		if(k==0)
		{
			cout<<0;
			return 0;
		}
		if(k==1)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					for(int l=i;l<=j;l++)
					{
						if(boook[l]==1)
						{
							ans++;
							break;
						}
					}
				}
			}
			cout<<ans;
			return 0;
		}
	}
	int sum,res,pos,next,ans=0;
	int maxnnnnnnnnn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
		    ans=0;
			for(int k=a[i];k<=a[j];k++)
			{
				memset(c,0,sizeof(c));
				memset(d,0,sizeof(d));
				res=1;
				sum=0;
				pos=1;
				next=0;
				int l=k,p=ans;
				while(l>0)
				{
					c[res]=l%2;
					l/=2;
					res++;
				}
				while(p>0)
                {
                    d[pos]=p%2;
                    p/=2;
                    pos++;
                }
                res--;
                pos--;
				for(int l=1;l<=max(pos,res);l++)
                {
                    sum+=max(c[l],d[l])*pow(2,next++);
                }
                ans=sum;
			}
			if(ans==k)
              //  cout<<i<<" "<<j<<"\n";
                maxnnnnnnnnn++;
		}
	}
	cout<<maxnnnnnnnnn;
	return 0;
}
