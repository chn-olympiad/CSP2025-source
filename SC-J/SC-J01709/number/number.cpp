#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[1000009];
int cnt,vist;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			cnt++;
			a[cnt]=s[i];
		}
	}
	sort(a+1,a+cnt+1);
	vist=cnt;
	while(cnt!=0)
	{
		if(cnt==vist&&a[cnt]=='0')
		{
			cout<<0;
			break; 
		}
		cout<<a[cnt];
		cnt--;
	}
	return 0;
}