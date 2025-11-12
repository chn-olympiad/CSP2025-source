#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,m=0,l,b=0;
	cin>>n;
	int a[100000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>=3)
	{
		for(int i=1;i<=3;i++)
	   {
		if(m<a[i])
		  m=a[i];
	   }
		l=a[1]+a[2]+a[3];
	    if(l>2*m)
	  {
		 b++;
	  }
	    m=0;
	  for(int i=1;i<=4;i++)
	   {
		if(m<a[i] && i!=3)
		  m=a[i];
	   }
	    l=a[1]+a[2]+a[4];
	    if(l>2*m)
	  {
		b++;
 	  }
 	  m=0;
 	  for(int i=1;i<=5;i++)
	   {
		if(m<a[i] && i!=5 && i!=3)
		  m=a[i];
	   }
 	    l=a[1]+a[2]+a[5];
	    if(l>2*m)
	  {
		b++;
 	  }
 	  m=0;
 	  for(int i=1;i<=5;i++)
	   {
		if(m<a[i] && i!=2)
		  m=a[i];
	   }
 	    l=a[1]+a[3]+a[4];
	    if(l>2*m)
	  {
		b++;
 	  }
 	  m=0;
 	  for(int i=1;i<=5;i++)
	   {
		if(m<a[i] && i!=2 && i!=4)
		  m=a[i];
	   }
 	    l=a[1]+a[3]+a[5];
	    if(l>2*m)
	  {
		b++;
 	  }
 	  m=0;
 	  for(int i=2;i<=4;i++)
	   {
		if(m<a[i] && i!=1)
		  m=a[i];
	   }
 	    l=a[2]+a[3]+a[4];
	    if(l>2*m)
	  {
		b++;
 	  }
 	  m=0;
 	  for(int i=1;i<=5;i++)
	   {
		if(m<a[i] && i!=1 && i!=4)
		  m=a[i];
	   }
 	    l=a[2]+a[3]+a[5];
	    if(l>2*m)
	  {
		b++;
 	  }
 	  m=0;
 	  for(int i=1;i<=5;i++)
	   {
		if(m<a[i] && i!=2 && i!=3)
		  m=a[i];
	   }
		l=a[1]+a[4]+a[5];
	    if(l>2*m)
	  {
		 b++;
	  }
	    m=0;
	    for(int i=1;i<=5;i++)
	   {
		if(m<a[i] && i!=1 && i!=3)
		  m=a[i];
	   }
		l=a[2]+a[4]+a[5];
	    if(l>2*m)
	  {
		 b++;
	  }
	    m=0;
	    for(int i=3;i<=5;i++)
	   {
		if(m<a[i])
		  m=a[i];
	   }
		l=a[3]+a[4]+a[5];
	    if(l>2*m)
	  {
		 b++;
	  }
	    m=0;
	}
	if(n>=4)
	{
	    for(int i=1;i<=4;i++)
	    {
	   	  if(m<a[i])
	   	  {
	   	  	m=a[i];
		  }
	    }
	    l=a[1]+a[2]+a[3]+a[4];
	    if(l>2*m)
	    {
	    	b++;
	    	m=0;
		}
	    for(int i=1;i<=5;i++)
	    {
	   	  if(m<a[i] && i!=2)
	   	  {
	   	  	m=a[i];
		  }
	    }
	    l=a[1]+a[3]+a[4]+a[5];
	    if(l>2*m)
	    {
	    	b++;
	    	m=0;
		}
		for(int i=1;i<=5;i++)
	    {
	   	  if(m<a[i] && i!=3)
	   	  {
	   	  	m=a[i];
		  }
	    }
	    l=a[1]+a[2]+a[4]+a[5];
	    if(l>2*m)
	    {
	    	b++;
	    	m=0;
		}
		for(int i=1;i<=5;i++)
	    {
	   	  if(m<a[i] && i!=1)
	   	  {
	   	  	m=a[i];
		  }
	    }
	    l=a[2]+a[3]+a[4]+a[5];
	    if(l>2*m)
	    {
	    	b++;
	    	m=0;
		}
		for(int i=1;i<=5;i++)
	    {
	   	  if(m<a[i] && i!=4)
	   	  {
	   	  	m=a[i];
		  }
	    }
	    l=a[1]+a[2]+a[3]+a[5];
	    if(l>2*m)
	    {
	    	b++;
	    	m=0;
		}
	}
	if(n>=5)
	{
		for(int i=1;i<=5;i++)
		{
			if(m<a[i])
			  m=a[i];
		}
		l=a[1]+a[2]+a[3]+a[4]+a[5];
		if(l>2*m)
		  b++;
	}
	cout<<b;
	return 0;
}