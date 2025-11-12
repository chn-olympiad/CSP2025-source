#include<bits/stdc++.h>
using namespace std;
int n,ans,lon,maxx;
int anss;
int l[10000],f[10000]; 
int check(int m)
{
	int i=1,j=1,ll=0;
	maxx=0;
	while (i<=m)
	{
		if (f[j]==1)
		{
			maxx=max(maxx,l[j]);
			ll+=l[j];
			i++;
		}
		j++;
	}
	if (ll>maxx*2) return 1;
	return 0; 
}
void find (int m,int now,int last)
{
	if (now+1>m) 
	{
	   	if (check(m)==1)
	    {
	    	ans++;
	    /*	for (int i=1;i<=m;)
	    	{
	    	    if (f[i]==1) 
				{
					cout<<i<<" ";
					i++;
				}
			}
		*/
		}
	    cout<<anss<<endl;
	    return;
	}
	for (int i=last+1;i<=m;i++)
	{   
	    f[i]=1;
		anss*=10;
		anss+=i;
		find(m,now+1,i);
		anss-=i;
		anss/=10;
		f[i]=0;
	}
}
int main(){
    freopen("polygon.in","r",stdin);	
    freopen("polygon.out","w",stdout);		
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>l[i];
		lon+=l[i];
		maxx=max(maxx,l[i]);
	}
	if (n<=3) 
	{
		if (lon>maxx*2)
		cout<<1;
		else cout<<0;
	}
	else
	{
		if (maxx==1)
		{
			cout<<n-2;
		} 
		else
		{
	        sort(l+1,l+n+1);
	        for (int i=3;i<=n;i++)
	        {
	    	    find(i,0,0);
	        }
	        cout<<ans;				
		}
	}

	return 0;
}
