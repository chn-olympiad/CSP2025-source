#include<bits/stdc++.h>
using namespace std;
string s;
bool f=false;
long long n,i,j,a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		a[s[i]-'0']++;
	}
	for(i=9;i>=0;i--)
	{
		for(j=0;j<a[i];j++)
		{
			if(i>0)
			{
				f=true;
			}
			if(i==0&&!f)
			{
				cout<<0;
				return 0;
			}
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
