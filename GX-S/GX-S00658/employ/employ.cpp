#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],d,m1,b,l=0;
string s;     
int main()
{     
    freopan("employ.in","r",stdin);
    freopan("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    { 
		cin>>a[i];
	}
	if(m==n){
		if(n==1){
			cout<<1;
			return 0;
		}
		else{
		for(int i=1;i<=n;i++)
        { 
		    if(a[i]>n)
		    {
			l++;
		    }
	    }
	        if(l!=0){
			    cout<<0;
			    return 0;
		    }	
		}
		
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
		    if(a[j]<=a[j-1])
		    {
			d=a[j-1];
			a[j-1]=a[j];
			a[j]=d;
	        }
		}
		if(a[i]<=i)
		{
			m1++;
		}
		if(m1>=m)
		{
			b++;
		}
	}
	cout<<b%998244353;
	
    return 0;
}
