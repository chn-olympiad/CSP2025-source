#include <bits/stdc++.h>
using namespace std;
int a[510];
int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int cnt=0,ans=0;
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			a[i]=0;
			a[i+1]--;
		}
		if(a[i]>0)
		{
			cnt++;
		}
		if(cnt>=m)
		{
			ans++;
		}
	}
	cout<<ans*cnt;
	return 0;
}
