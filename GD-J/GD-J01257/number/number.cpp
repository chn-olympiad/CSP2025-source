#include<iostream>
#include<algorithm>
using namespace std;
string s;
int a[1000005],cnt;
int main()
{
	freopen("numder.in","r",stdin);
	freopen("numder.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]<=58&&s[i]>=48)
		{
			cnt++;
			a[cnt]=s[i];
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<char(a[i]);
	}
	return 0;
} 
