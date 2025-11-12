#include<bits/stdc++.h>
using namespace std;
int a[1000005]={0},b[10]={0};

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sum=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			a[sum]=s[i]-'0';
			sum++;
		}
	}
	for(int j=0;j<sum;j++)
	{
		b[a[j]]++;
	}
	for(int h=9;h>=0;h--)
	{
		for(int x=1;x<=b[h];x++)
		{
			cout<<h;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
