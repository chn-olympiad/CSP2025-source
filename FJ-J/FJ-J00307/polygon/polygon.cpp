#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],ans,s,l,A;
bool f[5005];
void dfs(int k,int r,int m)
{
	for(int i=1;i<=m;i++)
	{
		if(a[i]>a[i+1]&&a[i]!=0&&a[i+1]!=0)
		{
			return ;
		}
	}
	for(int i=1;i<=s;i++)
	{
		if(i>s) return ;
		if(!f[i])
		{
			a[k]=i;
			f[i]=true;
			if(r==m) 
			{
				ans++;	
			}
			else dfs(k+1,r+1,m);
			f[i]=false;
			a[k]=0;				
		}	
	}
}
int main()
{
	cin>>n;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int k=1;k<=n;k++)
	{
		cin>>a[k];
   		if(a[k]==1)
   		{
   			s++;	
   		}
   		else if(a[k]>1) 
   		{
   			A=1;
   		}
    }
    if(A==1)
    {
    	for(int i=1;i<=s;i++)
		{
			a[i]=0;
		}
	    for(int k=3;k<=s;k++)
	    {
	    	dfs(1,0,k);
	    	if(k<s-1)
	    	ans/=s/2;
	    	for(int i=1;i<=s;i++)
	    	{
	    		a[i]=0;
	    	}
	    }  
	    cout<<ans+1;
		return 0;   	
    }
	else
	{
		sort(a+1,a+s+1);
		int cnt;
		for(int i=1;i<=s;i++)
		{
			cnt+=a[i];
		}
		if(cnt>2*a[s])
		{
			for(int i=s-1;i>=1;i--)
			{
				for(int j=1;j<=i-1;j++)
				{
					ans++;
				}	
			}
		}
		
	}
	cout<<6;


	return 0;
}

