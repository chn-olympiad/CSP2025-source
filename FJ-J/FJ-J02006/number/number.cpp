#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int m;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[++m]=s[i]-48;
	}
	sort(a+1,a+1+m,greater<int>());
	for(int i=1;i<=m;i++) cout<<a[i];
	cout<<endl;
	return 0;
}