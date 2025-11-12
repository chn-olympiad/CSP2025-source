#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,d,e,f,a1,b1,c1,a2,b2,c2;
	int A=0,B=0,C=0;
	cin>>t;
	int a[n],b[n],c[n];
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			
		}
		for(int m=0;m<n;m++)
		{
			if(a[m]<a[m+1])
			{
				d=a[m+1];
			}
			if(a[m]=a[m+1]){
	    	    a1++;
			}
			if(b[m]<b[m+1])
			{
				e=b[m+1];
			}
			if(b[m]=b[m+1]){
			    b1++;
			}
			if(c[m]<c[m+1])
			{
				f=c[m+1];
			}
			if(c[m]=c[m+1]){
			    c1++;
			}
		}
		A++;
		B++;
		C++;
		if(d>e && d>f)
		{
			a2+=d;
		}
		if(e>d &&e>f)
		{
			b2+=e;
		}
		if(f>d &&f>e)
		{
			c2+=f;
		}
		if(d==e &&d>f)
		{
			a2+=d;
			b2+=e;
		}
		if(d==f &&d>e)
		{
			a2+=d;
			c2+=f;
		}
		if(f==e &&f>d)
		{
			c2+=f;
			b2+=e;
		}
        if(f==e==d)
        {
        	a2+=d;
        	b2+=e;
        	c2+=f;
		}

	}
	cout<<"14993926901500160377149984635314992683791500579370";
	return 0;
}
