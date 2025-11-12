#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N]={};
int cnt=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<=l-1;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[cnt]=int(s[i])-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt);
	for(int i=cnt-1;i>=1;i--)cout<<a[i];
	return 0;
}
