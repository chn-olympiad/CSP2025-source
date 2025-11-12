#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int a[N],t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[++t]=s[i]-'0';
	}
	sort(a+1,a+1+t);
	for(int i=t;i>=1;i--)
	{
		cout<<a[i];
		if(a[t]==0)break;
	}
	return 0;
}