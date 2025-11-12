#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int len=s.size(),t=1;
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[t++]=int(s[i]-'0');
	sort(a+1,a+t,cmp);
	for(int i=1;i<=t-1;i++)
		ans=ans*10+a[i];
	cout<<ans;
	return 0;
}
