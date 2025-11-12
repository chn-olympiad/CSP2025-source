#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5; 
string s;
int a[maxn];
bool cmp(int pre,int nxt)
{
	return pre>nxt;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0; 
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[++j]=s[i]-'0';
	}
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j;i++)
		cout<<a[i];
	return 0;
}
