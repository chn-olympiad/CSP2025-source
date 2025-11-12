#include<bits/stdc++.h>
using namespace std;

long long a[5005];
long long n;
long long sum=0;//方法 
long long num=0;//长度 
bool b[5005];

void sss(int x,int y,int k,int maxn)
{
	int mmm=maxn;
	int kkk=k;
	bool l=false;
	for(int i=1;i<=n;i++)
	{
		if(b[i])
		{
			l=true;
			b[i]==false;
			k+=a[i];
			x++;
			
			if(a[i]>maxn)
			{
				maxn=a[i];
			}
			if(x==y && k>(2*maxn))
			{
				sum++;
				sss(x-1,y,kkk,mmm);
			}
			else
			{
				sss(x,y,k,maxn);	
			}
		}
	}
	if(l==false)
	{
		if(x==0)
		{
			return;
		}
		else
		{
			sss(x-1,y,kkk,mmm);
		}
	}	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=true;
	}
	for(int i=3;i<=n;i++)
	{
		sss(0,i,0,-1);
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//5 1 2 3 4 5
