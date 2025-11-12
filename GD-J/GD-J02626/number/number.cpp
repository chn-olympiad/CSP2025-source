#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int now=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[now]=s[i]-'0';
			now++;
		}
	}
	sort(a+1,a+now+1,cmp);
	for(int i=1;i<now;i++)printf("%d",a[i]);
	return 0;
}
