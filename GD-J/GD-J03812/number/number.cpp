#include<bits/stdc++.h>
using namespace std;
string s;
int num[100];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(num,0,sizeof(num));
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (s[i]>='0'&&s[i]<='9')
			num[s[i]-'0']++;
	for (int i=9;i>=0;i--)
		while (num[i]>0)
		{
			printf("%d",i);
			num[i]--;
		}
	return 0;
} 
/*
8:43  Finish OK 
10:27 Check OK
I want AC!
RP++
*/ 
