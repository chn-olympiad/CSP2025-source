#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream in("polygon.in");
	ofstream out("polygon.out");
	int a,k,l;
	in>>a;
	int s[a],b[a];
	for(int i=0;i<a;i++)
	{
		in>>s[i];
	}
	for(int j=0;j<a;j++)
	{
		k=0;
		for(int i=1;i<a;i++)
		{
			if(s[i]>s[k])
			{
				k=i;
			}
		}
		b[j]=s[k];
		s[k]=-1;
	}
	for(int i=0;i<a-2;i++)
	{
		l=b[i];
	}
	in.close();
	out.close();
	return 0;
}
