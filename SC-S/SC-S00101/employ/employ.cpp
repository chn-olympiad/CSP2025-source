#include<bits/stdc++.h>
using namespace std;
int c[505];
int l[505];
int num[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	
	int n,m;
	string s;
	int po=0;
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		num[c[i]]++;
	}
	sort(c+1,c+1+n);
	int ans=1;
	if(m==1)
	{
		ans=n-num[0];
		for(int i=1;i<=n-1;i++)
		{
			ans=ans*i;
			ans=ans%998244353;
		}
		cout<<ans;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			cnt++;
			l[cnt]=i+1;
		}
	}
	long long ans1=1;
	for(int i=1;i<=n;i++)
	{
		ans1=ans1*i;
		ans1=ans1%998244353;
	}
	printf("%d",ans1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}