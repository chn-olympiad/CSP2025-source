#include<bits/stdc++.h>
using namespace std;
int cnt,a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		int y=s[i]-'0';
		if(y>=0&&y<=9) a[y]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++) printf("%d",i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
