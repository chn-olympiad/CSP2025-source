#include<bits/stdc++.h>
using namespace std;
string n;
string x;
char m[10]={'0','1','2','3','4','5','6','7','8','9'};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int y=0;
	for(int i=0;n[i]=='0';i++)
	{
		for(int j=0;j<10;j++)
		{
			if(n[i]==m[j])
			{
				x[i]=n[i];
				y++;
			}
		}
	}
	sort(x,x+y);
	for(int i=0;i<y;i++)
	{
		cout<<x[i];
	}
	return 0;
}