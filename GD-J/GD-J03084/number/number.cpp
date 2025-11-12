#include<bits/stdc++.h>
using namespace std;
char a[2001000];
long long n,ans[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>a+1;
	n=strlen(a+1);
	for(int i=1;i<=n;i++)
	{
//		cout<<"1\n";
		if(a[i]<='9'&&a[i]>='0')
		{
			ans[a[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=ans[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
