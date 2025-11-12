#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
char a[N];
int cnt;
bool cmp(char x,char y)
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
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i];
		}
	} 
	sort(a+1,a+cnt+1,cmp);
	cout<<a+1;
	return 0;
}
