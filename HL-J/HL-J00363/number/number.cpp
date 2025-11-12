#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000005];
int num;
bool rule(int x,int y)
{
	if(x<y)
		return false;
	else
		return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int m=s.length();
	int j=0;
	for(int i=0;i<m;i++)
	{
		if(s[i]-'0'<10)
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j,rule);
	for(int i=0;i<j;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
