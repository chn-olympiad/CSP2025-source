#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=1,s1;
	cin>>s;
	s1=s.size();
	for(int i=0;i<s1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>1;i--)
	cout<<a[i];
	return 0;
}
