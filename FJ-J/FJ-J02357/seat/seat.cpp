#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,h,l;
    cin>>n>>m;
    vector<int> cj;
	for(int i=1;i<=n*m;i++)
	{
		cin>>cj[i];
	}
	l=cj[1];
	for(int k=1;k<=5;k++)
	{
	    for(int j=1;j<=cj.size();j++)
		{
		    if(cj[j]<cj[j+1])
			{
	    		h=cj[j+1];
				cj[j+1]=cj[j];
				cj[j]=h;
			}
		}
    }
    if(l==cj[1])
    {
    	cout<<1<<1;
	}
	if(l==cj[2])
    {
		cout<<1<<2;
    }
    if(l==cj[3])
	{
		cout<<1<<3;
	}
	if(l==cj[4])
	{
    	cout<<1<<4;
	}
	if(l==cj[5])
	{
		cout<<1<<5;
	}
	if(l==cj[6])
	{
		cout<<2<<5;
	}
	if(l==cj[7])
	{
    	cout<<2<<4;
	}
	if(l==cj[8])
	{
    	cout<<2<<3;
	}
    return 0;
}
