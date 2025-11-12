/*
欸t1怎么这么水
拿个vector装吧懒得手写了
欸不是大样例怎么挂了 
算了大样例懒得对了
手写吧 

10:31打了一个Hash发现大样例没挂
不是这要是挂了我也是神人了

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
char ans[1000001];
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),top=0;
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans[++top]=s[i];
		}
	}
	sort(ans+1,ans+top+1,cmp);
	for(int i=1;i<=top;i++)
	{
		cout<<ans[i];
	}
}
