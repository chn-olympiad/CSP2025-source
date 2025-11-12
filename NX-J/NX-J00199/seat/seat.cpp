#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen(seat.in,"r",stdin)
    freopen(seat.out,"w",stdout)
	string a;
	int b,c,d=0;
	cin>>b>>c;
	for(int i=0;i<=b*c;i++)
	{
		cin<<a;
	}
	for(int i=0;i<=b*c-1;i++)
	{
		if (a.size(0)<a.size(i))
		{
			d=d+1;
		}
	}
	cout<<d/b<<","d-d/b;


  return 0;
}
