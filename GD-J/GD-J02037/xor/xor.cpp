#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,k,a[N],ans=-1,ll[N],rr[N],m=1,zl,zr,news=0;
bool f=true;
long long yh(int l,int r)
{
	long long ans=a[l];
	for(int i=l+1;i<=r;i++) ans=ans^a[i];
	return ans;
}
bool p(int l1,int r1,int l2,int r2)
{
	for(int i=min(l1,l2);i<=max(r1,r2);i++)
	{
		if(i>=l1&&i<=r1&&i>=l2&&i<=r2) return false;
	}
	return true;
}
void x(long long n)
{
	if(n==m)
	{
		for(int i=1;i<m;i++)
		{
			if(i!=1){
			if(p(zl,zr,ll[i+1],rr[i+1])==false)
			{
				return;
			}else
			{
				zl=max(zl,ll[i+1]);zr=max(zr,rr[i+1]);
			}
		    }else
		    {
			    if(p(ll[i],rr[i],ll[i+1],rr[i+1])==false)
			    {
			     	return;
			    }else
			    {
			    	zl=max(ll[i],ll[i+1]);zr=max(rr[i],rr[i+1]);
				}
		    }
		}
		ans=m;
	}
	if(n==1)
	{
		ans=1;
		x(2);
	}else{
	    for(int i=1;i<=m-n+1;i++)
		{
			f=true;
			for(int j=i;j<i+n;j++)
			{
			
			    if(i!=1){
			        if(p(zl,zr,ll[i+1],rr[i+1])==false)
			        {
			        	f=false;
		        		break;
		        	}else
			        {
			        	zl=max(zl,ll[i+1]);zr=max(zr,rr[i+1]);
			        }
		        }else
		        {
		    	    if(p(ll[i],rr[i],ll[i+1],rr[i+1])==false)
			        {
			        	f=false;
			         	break;
			        }else
			        {
			        	zl=max(ll[i],ll[i+1]);zr=max(rr[i],rr[i+1]);
			    	}
		        }
		    }
		    if(f==true)
		    {
		    ans=m;
		    break;
		    }
        }
        x(n+1);
    }
}
int main()
{
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(yh(i,j)==k)
			{
				ll[m]=i;
				rr[m]=j;
				m++;
			}
		}
	}
	x(1);
	cout<<ans;
	return 0;
} 
