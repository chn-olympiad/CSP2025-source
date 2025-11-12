#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
char s1[505];
bool s[505];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>s1[i];
		if(s1[i]=='1')s[i]=true;
		else s[i]=false;
	}
	for(int i=1;i<=n;++i)cin>>c[i];
	sort(c+1,c+1+n);
	int c1=1,sum=0;
	for(int i=1;i<=n;++i)
	{
		if(c1>c[i])continue;
		if(s[i])sum++;
	}
	cout<<sum;
	return 0;
}

