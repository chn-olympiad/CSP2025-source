#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m;
int c[510];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]==0)
			flag=false;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(flag==true)
	{
		int cnt1,cnt2=m;
		int sum1=n,sum2=m;
		cnt1=n;
		for(int i=1;i<m;i++)
		{
			cnt1--;
			sum1*=cnt1;
			sum1%=p;
		}
		for(int i=1;i<m;i++)
		{
			cnt2--;
			sum2*=cnt2;
			sum2%=p;
		}
		cout<<(sum1/sum2%p);
	}
	if(m==1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0)
				cnt++;
			if(s[i]==1)
				continue;
		}
		int cn=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]<=cnt)
				cn++;
		}
		cout<<(n-cn)%p;
	}
	cout<<0;
	return 0;
}
