#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int n,ljn[N],cnt;
int main ()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ljn[++cnt]=int(s[i]-'0');
		}
	}
	sort(ljn+1,ljn+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		printf("%d",ljn[i]);
	}
	return 0;
}