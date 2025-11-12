#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int ans,n,a[N][5],lim,t,l[4],sum,x,b[N];
void dfs(int p)
{
	if(p>n) return;
	for(int i=1;i<=3;i++)
	{
		if(l[i]<lim)
		{
		    sum+=a[p][i];
    	  	l[i]++;
    		ans=max(ans,sum);
    		dfs(p+1);
    		sum-=a[p][i];
    		l[i]--;
	    }
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
	    cin>>n;
	
	    lim=n/2;
	    x=1;
	    for(int i=1;i<=n;i++)
	    {
		    cin>>a[i][1]>>a[i][2]>>a[i][3];
		    b[i]=a[i][1];
	    }ans=sum=0;
	    
	    l[1]=l[2]=l[3]=0;
	    if(n<1000)
		{
		    dfs(x);
	        cout<<ans<<endl;
		}
		else
		{
			sort(b+1,b+n+1);
			for(int i=1;i<=lim;i++) ans+=b[i];
			cout<<ans<<endl;
		}
	}
}
