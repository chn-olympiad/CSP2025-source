#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int ans,cnt,a[10000003];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--)
		cout<<a[i];
	return 0;
}
