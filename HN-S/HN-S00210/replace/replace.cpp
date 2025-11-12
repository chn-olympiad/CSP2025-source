#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	char s[114514][114514];
	char t[114514][114514];
	for(int i;i<=n;i++)
	{
		cin>> s[i][1]>>s[i][2];
	}
	int j;
	for(j<=q;j++;)
	{
		cin>>t[j][1]>>t[j][2];
	}
	for(int re;re<q;re++)
	{
		cout<<j<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
