#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[200][200];
int k,p,w1=0,w2=0,w3=0;
void op(int b)
{
	while(3){
		for(int i=1;i<=n+1;i++)
	{
		p+=k;
		for(int j=1;j<=3;j++)
		{
			if(k<a[i][j])
			{
				k=a[i][j];
			}
			if(a[i][1]==k)
			{
				w1++;
			}
			if(a[i][2]==k)
			{
				w2++;
			}
			if(a[i][3]==k)
			{
				w3++;
			}
			
		}
	}
	if(w1>=n/2&&w2>=n/2&&w3>=n/2)
	{
		k=0;
		for(int i=1;i<=n+1;i++)
	{
		
		for(int j=1;j<=3;j++)
		{
			if(k<a[i][j])
			{
				a[i][j+1]=a[i][j];
			}
			
		}
	}
		for(int i=1;i<=n+1;i++)
	{
		p+=k;
		for(int j=1;j<=3;j++)
		{
			if(k<a[i][j])
			{
				k=a[i][j];
			}
			if(a[i][1]==k)
			{
				w1++;
			}
			if(a[i][2]==k)
			{
				w2++;
			}
			if(a[i][3]==k)
			{
				w3++;
			}
			
		}
	}
	}
}
	}
	
int main()
{
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=1;j<=n+1;j++)
		{
			for(int m=1;m<=3;m++)
			{
				cin>>a[j][m];
			}
		}
	}
	
	for(int m=0;m<t;m++)
	{
		
		p=0;
		op(n);
		cout<<p<<endl;
	}
	return 0;
}
