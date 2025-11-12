#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	long long a,b,r,w=0;
	vector<long long> v;
	cin>>a>>b;
	for(int i=0;i<a*b;i++)
	{
		cin>>r;
		w+=r;
		v.push_back(r);
	}
	w=w/(a*b);
	if(v[0]<w)
	{
		if(a%2==1)
		{
			a=a+1;
		}
		else if(b%2==1)
		{
			b=b+1;
		}
		cout<<a/2<<" "<<b/2;
	}
	else if(v[0]>w)
	{
		if(a%2==1)
		{
			a=a-1;
		}
		else if(b%2==1)
		{
			b=b-1;
		}
		cout<<a/2<<" "<<b/2;
	}
	else if(v[0]==w)
	{
		if(a%2==1)
		{
			a=a+1;
		}
		else if(b%2==1)
		{
			b=b+1;
		}
		cout<<a/2<<" "<<b/2;
	}
	return 0;
}
 
