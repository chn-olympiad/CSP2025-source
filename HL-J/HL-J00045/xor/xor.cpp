#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream in("xor.in");
	ofstream out("xor.out");
	int n,a;
	in>>n;
	int c[n+1][20];
	for(int i=0;i<n+1;i++)
	{
		in>>a;
		int x=0;
		while(a>0)
		{
			if(a%2==0)
			{
				c[i][x]=0;
			}
			else
			{
				c[i][x]=1;
			}
			a/=2;
			x+=1;
		}
	}
	
	out.close();
	in.close();
	return 0;
}
