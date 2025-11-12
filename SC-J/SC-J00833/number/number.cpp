#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int b[N],k=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(cin>>c)
	{
		if(c>='0' && c<='9')
		b[c-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(b[i]!=0)
		{
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}