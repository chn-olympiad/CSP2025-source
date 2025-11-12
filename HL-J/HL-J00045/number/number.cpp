#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream in("number.in");
	ofstream out("number.out");
	string s;
	int m=0;
	int k=0;
	int ans;
	in>>s;
	int a[sizeof(s)];
	for(int i=0;i<sizeof(s);i++)
	{
		if(isdigit(s[i]))
		{
			a[m]=int(s[i]);
			m+=1;
		}
	}
	int b[sizeof(a)];
	for(int j=0;j<sizeof(a);j++)
	{
		for(int i=1;i<sizeof(a);i++)
		{
			if(a[i]>a[k])
			{
				k=i;
			}
		}
		b[j]=a[k];
		a[k]=-1;
	}
	for(int i=sizeof(a)-1;i>=0;i--)
	{
		int ten=1;
		for(int n=0;n<i;n++)
		{
			ten*=10;
		}
		ans+=b[sizeof(a)-i-1]*ten;
	}
	out<<ans;
	in.close();
	out.close();
	return 0;
}
