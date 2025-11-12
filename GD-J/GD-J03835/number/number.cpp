#include<iostream>
#include<algorithm>
using namespace std;
string s;
int num[1000015];
int cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')num[++cnt]=s[i]-'0';
	}
	sort(num+1,num+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)cout<<num[i];
}
