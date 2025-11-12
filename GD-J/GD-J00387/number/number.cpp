#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
string s;
char num[N];
int n=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			num[n++]=s[i];
	sort(num,num+n);
	while(num[n-1]=='0'&&n!=1) n--;
	for(int i=n-1;i>=0;i--)
		cout<<char(num[i]);
	return 0;
}
