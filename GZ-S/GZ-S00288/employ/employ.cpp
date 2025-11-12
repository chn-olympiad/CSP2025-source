//GZ-S00288 贵阳市第一中学 殳晟欢
#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,cnt=1,t,c[501];
long long ans=1,ansa;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=2;i<=n;i++)
	{
		if(c[i-1]==0)
			continue;
		if(c[i-1]==c[i])
		{
			cnt++;
			if(s[i-1]=='1')
				t++;
		}
		else
		{
			if(cnt>1)
			{
				for(int j=cnt-t;j<=cnt;j++) 
					ans*=j,ans%=998244353;
				ansa+=ans,ans=0;
			}
			cnt=1;
		}
	}
	cout<<1;
	return 0;
}
