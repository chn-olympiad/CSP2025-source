#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)if(s[i]>='0'&&s[i]<='9')a[++num]=s[i]-'0';
	sort(a+1,a+1+num);
	if(a[num]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=num;i>=1;i--)cout<<a[i];
	return 0;
}