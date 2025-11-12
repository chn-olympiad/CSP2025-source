#include<bits/stdc++.h>
using namespace std;
int cnt[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	while(cin>>s)
	{
		if(s>='0'&&s<='9')
		  cnt[s-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=cnt[i];j++)
		  cout<<i;
	}
}