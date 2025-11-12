#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
    {
	    w=-1;
		ch=getchar();     	
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
int n,m,r,ans=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	n=read();
	m=read();
	r=read();
	for(int i=1;i<n*m;i++)
	{
		if(r<read())
		{
			ans++;
		}
	}
	if(((ans+n-1)/n)%2==1)
	{
		cout<<((ans+n-1)/n)<<" ";
		if(ans%n==0)
		{
			cout<<n;
		}
		else  cout<<ans%n;
	}
	else
	{
		cout<<((ans+n-1)/n)<<" ";
		if(ans%n==0)
		{
			cout<<1;
		}
		else
		{ 
		    cout<<n-(ans%n)+1;
	    }
	}
	fclose(stdin);
	fclose(stdout); 
}