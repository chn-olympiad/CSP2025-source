#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],k;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[++k]=s[i]-'0';
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++)
		cout<<a[i];
	return 0;
}
