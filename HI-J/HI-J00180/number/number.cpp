#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
char s[1000001];
int t[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;;i++)
	{
		if(s[i] < 0)
		{
			break;
		}
		
		if(s[i] == '1')
			t[1]++;
		else if(s[i] == '2')
			t[2]++;
		else if(s[i] == '3')
			t[3]++;
		else if(s[i] == '4')
			t[4]++;
		else if(s[i] == '5')
			t[5]++;
		else if(s[i] == '6')
			t[6]++;
		else if(s[i] == '7')
			t[7]++;
		else if(s[i] == '8')
			t[8]++;
		else if(s[i] == '9')
			t[9]++;
		else if(s[i] == '0')
			t[0]++;
	}
	
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 1;j <= t[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}

