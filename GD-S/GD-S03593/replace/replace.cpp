#include<bits/stdc++.h>
using namespace std;
long n,q,ans;
string s[200010][3],t[200010][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(long i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
	}
	for(long i=1;i<=q;i++)
	{
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
