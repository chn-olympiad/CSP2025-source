#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int num[N];
int cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+1+cnt);
	for(int i=cnt;i>=1;i--)cout<<num[i];
	return 0;
}
