#include<bits/stdc++.h>
using namespace std;
int t[500];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(scanf("%c",&c)!=EOF)
		t[(int)c]++;
	for(char i='9';i>='0';i--)
	{
		while(t[(int)i]!=0)
		{
			printf("%c",i);
			t[(int)i]--;
		}
	}
	return 0;
}
