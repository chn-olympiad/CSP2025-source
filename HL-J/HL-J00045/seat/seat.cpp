#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream in("seat.in");
	ofstream out("seat.out");
	int m,n,a,k,km,kn;
	int num=1;
	in>>n;
	in>>m;
	in>>k;
	for(int i=1;i<n*m;i++)
	{
		in>>a;
		if(a>k)
		{
			num+=1;
		}
	}
	if(num%n==0)
	{
		km=num/n;
	}
	else
	{
		km=num/n+1;
	}
	if(km%2==0)
	{
		kn=n-(num-1)%n;
	}
	else
	{
		if(num%n==0)
		{
			kn=n;
		}
		else
		{
			kn=num%n;
		}
	}
	out<<km<<" "<<kn;
	in.close();
	out.close();
	return 0;
}
