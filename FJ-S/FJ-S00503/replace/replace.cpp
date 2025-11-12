#include<bits/stdc++.h>
using namespace std;
int n,m;
char s1[5000002];
char s2[5000002];
long long ans[200005];
long long num[5000002];
long long s[5000002];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s1+1;
		cin>>s2+1;
		num[strlen(s2+1)]++;
	}
	long long base=5*1e6;
	for(int i=1;i<=base;i++)
	{
		s[i]=s[i-1]+num[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s1+1;
		cin>>s2+1;
		cout<<s[base]-s[strlen(s1+1)-1]<<endl;
	}
}
