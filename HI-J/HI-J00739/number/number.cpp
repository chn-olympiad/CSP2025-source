#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
const int N=1e6+10;
char ans[N];
char s[N];
int tot;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			ans[tot]=s[i];
			tot++;
		}
	}
	sort(ans,ans+tot,cmp);
	cout<<ans;
	return 0;
}
