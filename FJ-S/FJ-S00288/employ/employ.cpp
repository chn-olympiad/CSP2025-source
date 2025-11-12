#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
char s[510];
int c[510],l[510]={0};
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>s[i];
	for (int i=1;i<=n;i++)
		cin>>c[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (c[j]>=i-1) l[i]+=1;
	for (int i=1;i<=n;i++)
	{
		if (l[i]!=0&&s[i]=='1')
			ans=ans*l[i]%N;
	}
	cout<<ans;
	return 0;
}

