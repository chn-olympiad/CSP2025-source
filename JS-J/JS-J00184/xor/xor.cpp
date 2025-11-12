#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
bool s[500000][20];
int fj(int a,bool* e)
{
	int l;
	for(l=0;a>0;l++)
	{
		e[l]=a%2;
		a/=2;
	}
	return l ;
}
void ay(bool* a,bool* b)
{
	for(int i=0;i<20;i++)
	a[i]=b[i]^a[i];
	return ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,n,b=0;
	bool k[20]={};
	cin>>n>>a;
	fj(a,k);
	for(int i=0;i<n;i++)
	{
		cin>>a;
		fj(a,s[i]);
	}
	for(int i=0;i<n;i++)
	{
		int lk=1;
		for(int j=i;j<n;j++)
		{
			bool ans[20]={};
			for(int h=i;h<=j;h++)
			{
			ay(ans,s[h]);
	    	}
	    	for(int h=0;h<20;h++)
	    	{
				if(!(ans[h]==k[h]))
				{
					lk=0;
					break;
				}
			}
			if(lk)
			{
				b++;
				i=j;
		    	break;
		    }
		}
	}
	cout<<b;
	return 0;
}

