#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s1;
int cnt,a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(int i=0;i<s1.size();i++)
	{
		if(isdigit(s1[i]))
		{
			a[cnt++]=s1[i]-48;
		}
	}
	sort(a-1,a+cnt);
	for(int i=cnt-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
