#include<bits/stdc++.h>
using namespace std;
int s[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n=0;
	char c;
	while(cin>>c)
	{
		if(c=='\n')
			break;
		if(c>='0'&&c<='9')
		{
			++n;
			s[n]=c-'0';
		}
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;++i)
		cout<<s[i];
	return 0;
}
