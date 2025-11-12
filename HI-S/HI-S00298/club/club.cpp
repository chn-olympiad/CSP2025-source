#include<bits/stdc++.h>
using namespace std;
int a[10];
int b[10];
int u[1000000];
int g[1000000];

int main()
{
	freopen("club,in","r",stdin);
	freopen("club,out","w",stdout);
	int t,n,s=0,h=0,y=0;
	int k=0,l=0,o=0;
	cin >>t;
	for(int i=1;i<=t;i++)
	{
		int k=0,l=0,o=0,j=2;
		int f=0;
		cin>>n;
		
			cin>>a[1];
			cin>>a[2];
			cin>>a[3];
			
			cin>>b[1];
			cin>>b[2];
			cin>>b[3];
			

		
			if(a[j-1]>=a[j])
			{
					if(a[j-1]>=a[j+1])
				{
					s=a[j-1];
					k=k+1;
				}
				else
				{
					s=a[j+1];
					o=o+1;
				}
			}
			else{
				if(a[j]>=a[j+1])
				{
					s=a[j];
					l=l+1;
				}
				else
				{
					s=a[j+1];
					o=o+1;
				}
			}
			
		
		f=f+s;
		//
		
		s=s-s;
		if(k==1)
		{
			if(b[j]>=b[j+1])
				{
					s=b[j];
				
				}
				else
				{
					s=b[j+1];
				
				}
		}
		
		//
		
		if(l==1)
		{
					if(b[j-1]>=b[j+1])
				{
					s=b[j-1];
				
				}
				else
				{
					s=b[j+1];
				
				}
		}

		//
		if(o==1)
		{
				if(b[j-1]>=b[j])
			{	
			s=b[j-1];
			}
			else{
				
					s=b[j];
				
			}
		}
	f=f+s;

		 k=0,l=0,o=0,j=2;
		 
		
		
		

	if(b[j-1]>=b[j])
			{
					if(b[j-1]>=b[j+1])
				{
					h=b[j-1];
					k=k+1;
				}
				else
				{
					h=b[j+1];
					o=o+1;
				}
			}
			else{
				if(b[j]>=b[j+1])
				{
					h=b[j];
					l=l+1;
				}
				else
				{
					h=b[j+1];
					o=o+1;
				}
			}
			
		
		y=y+h;
		//
		
		
		if(k==1)
		{
			if(a[j]>=a[j+1])
				{
					h=a[j];
				
				}
				else
				{
					h=a[j+1];
				
				}
		}
		
		//
		
		if(l==1)
		{
					if(a[j-1]>=a[j+1])
				{
					h=a[j-1];
				
				}
				else
				{
					h=a[j+1];
				
				}
		}

		//
		if(o==1)
		{
				if(a[j-1]>=a[j])
			{	
			h=a[j-1];
			}
			else{
				
					h=a[j];
				
			}
		}
	y=y+h;
		if(y>=f)
		{
			g[i]=y;
		}
		else{
			g[i]=f;
		}

		u[i]=g[i];
	g[i]=0;
h=0,y=0,s=0,f=0;
	
		
		
		
		
	}
	
	for(int i=1;i<=t;i++)
	{
		cout<<u[i];
		cout<<endl;
	}
	
}
