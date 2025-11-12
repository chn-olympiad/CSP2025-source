#include<bits/stdc++.h>
using namespace std;
string s;
int a[11],tot;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	s=" "+s;
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']=a[s[i]-'0']+1,tot++;
	}
	for(int i=10;i>=0;i--)
	{
		while(a[i])
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
