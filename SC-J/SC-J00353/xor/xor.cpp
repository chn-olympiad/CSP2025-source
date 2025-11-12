#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt,ans,b,c,d;
bool vis[500005];
int qz(long l,long r)
{
	for(;l<=r;l++)
	{
		a[l]=a[l]^a[l+1];
	}
	return a[r];
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	memset(vis,1,sizeof(vis));
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) b++;
		if(a[i]==0) c++;
	}
	if(n<=100 && k==0 && b==n)
	{
		cnt=n;
	}
	else if(n<=200005 && k>=0 && k<=1 && b+c==n)
	{
		if(k==1) cnt=b;
		else 
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]==a[i-1] && a[i]==1) d++;
				else 
				{
					cnt+=floor(d*1.0/2);
					d=0;
				}
			}
			cnt+=c;
		}
	}
	else 
	{
		long long l=1,r=n,m=n;
		for(l=1;l<=r;l++)
		{
			for(r=n;r>l;r--)
			{
				if(qz(l,r)==k) 
				{
					for(int i=l;i<=r;i++)
					{
						if(vis[i]==1) ans++;
					}
					if(ans==r-l+1)
					{
						cnt++;
						for(int i=l;i<=r;i++)
						{
							vis[i]=0;
						}	
					}
				}
			}
			r=m-1;
			m--;
		}		
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}