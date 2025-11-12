#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int a[N],cnt=1;
bool cmp(int x,int y)
{
	return x>y;
}	
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}	
	}	
	cnt--;
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}	
