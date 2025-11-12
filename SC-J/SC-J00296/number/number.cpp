#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000010],tot;
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[++tot]=s[i]-'0';
	}
	sort(a+1,a+tot+1,cmp);
	if(a[1]==0)
		cout<<0<<"\n";
	for(int i=1;i<=tot;i++)
		cout<<a[i];
	cout<<"\n";
	return 0;
}