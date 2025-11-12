#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e6+5;
string s;
int num[N],siz;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	IOS;
	cin>>s;
	for(int i=0;i<(int)s.length();i++)
		if('0'<=s[i]&&s[i]<='9')
			num[++siz]=s[i]-'0';
	sort(num+1,num+siz+1,cmp);
	for(int i=1;i<=siz;i++)
		cout<<num[i];
	return 0;
}