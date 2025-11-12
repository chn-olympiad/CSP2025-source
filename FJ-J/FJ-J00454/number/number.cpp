#include<bits/stdc++.h>
using namespace std;
string s;
int a;
int b[10005],c=1,m=-10086,n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	for(int i=0;i<a;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			b[c]= s[i] - 48 ;
			c++;
		}
	}
	for(int i=1;i<c;i++)
	{
		for(int i=1;i<c;i++)
		{
			if(b[i] > m && b[i] != -1)
			{
				m=b[i];
				n=i;
			}
		}
		cout<<m;
		b[n]=-1;
		m=-10086;
	}

	return 0;
}
