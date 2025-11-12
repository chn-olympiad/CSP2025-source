#include<bits/stdc++.h>
using namespace std;
char s[1000005],c,cnt;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	while(cin>>c)
	{
		if(c>='0' && c<='9')
		{
			cnt++;
			s[cnt]=c;
		}
	}
	sort(s+1,s+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<s[i];
	}
	return 0;
}