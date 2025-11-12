#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int se[100];
int cmd(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c;
	cin>>a>>b;
	for(int i=0;i<a*b;i++)
	{
		cin>>se[i];
	}
	c=se[0];
	sort(se,se+a*b,cmd);
	for(int j=0;j<a*b;j++)
	{
		int s=(j)%(a*2)+1,r=int(j/a)+1;
		if(s>a)
		s=a*2-s+1;
		if(c==se[j])
		{
			cout<<r<<' '<<s;
			return 0;
		}
	}
	return 0;
}

