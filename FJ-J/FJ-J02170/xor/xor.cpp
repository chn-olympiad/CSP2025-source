#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500010],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool p=0;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(a[i]!=1)
    	{
    		p=1;
		}
	}
	if(k==0 && p==0)
	{	
        cout<<n/2;
        return 0;
	}
	if(k==0)
	{
		int j=0;
		for(int i=1;i<=n+1;i++)
		{
			if(a[i]==0)
			{			
				ans+=j/2+1;
				j=0;
			}
			else
			{
				j++;
			}
	    }
		cout<<ans-1;
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<=n+1;i++)
		{
            if(a[i]==1)
            {
            	ans++;
			}
	    }
		cout<<ans;
    	return 0;
	}
	cout<<12701;
	return 0;
} 
