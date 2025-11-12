#include<bits/stdc++.h>
using namespace std;
int n,m,c[100005],ans;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ,out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)
		cin>>c[i];
	for (int i=0;i<n;i++)
	{
		if (s[i]-'0'==1)
			ans++;
	}
	cout<<ans;
	return 0;
}
