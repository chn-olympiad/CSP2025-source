#include<bits/stdc++.h>
using namespace std;
struct per{
	char nan;
	int xin;
};
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n,m;
	char a[n+1]={};
	cin>>a;
	int b[n+1]={};
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	per c[n+1]={};
	for(int i=0;i<n;i++)
	{
		c[i].nan=a[i];
		c[i].xin=b[i];
	}
	int sad=0;
	int guo=0;
	int sum=0;
	do
	{
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
	}while(n);
	do
	{
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
	}while(n);
	do
	{
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
	}while(n);
	do
	{
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
	}while(n);
	do
	{
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==m)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
					guo--;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
				if(i==n)
				{
					for(int j=0;j<n;j++)
					{
						if(c[j].nan=='0')
						{
							sad++;
						}
						else if(c[j].nan=='1')
						{
							guo++;
						}
						if(c[j].xin<=sad)
						{
							guo--;
						}
						else
						{
							guo++;
						}
						if(guo==m){
							sum++;
							
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(c[i].nan=='0')
			{
				sad++;
			}
			else if(c[i].nan=='1')
			{
				guo++;
			}
			if(c[i].xin<=sad)
			{
				guo--;
			}
			else
			{
				guo++;
			}
			if(guo==m){
				sum++;
				
			}
		}
		if(n==n)
		{
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i].nan=='0')
				{
					sad++;
				}
				else if(c[i].nan=='1')
				{
					guo++;
				}
				if(c[i].xin<=sad)
				{
					guo--;
				}
				else
				{
					guo++;
				}
				if(guo==m){
					sum++;
					
				}
			}
		}
		n--;
	}while(n);
	int aaa=998244353;
	cout<<sum/aaa;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

