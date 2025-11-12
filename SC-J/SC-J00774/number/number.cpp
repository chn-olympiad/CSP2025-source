#include<bits/stdc++.h>
using namespace std;
int cnt[10];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.size()-1;
	for(int i=0;i<=a;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(cnt[i]>0)
		{
			cnt[i]--;
			printf("%d",i);
		}
	}
	return 0;
}