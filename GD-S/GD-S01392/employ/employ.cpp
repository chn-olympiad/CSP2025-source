#include<bits/stdc++.h>
#define ll long long
using namespace std;
string st;
int n,m,ans,c[1010],s[1010],sum;
void ac1()
{
	if(m>sum)
	{
		cout<<0;return ;
	}
	int v[1010]={0},j=1,kk,ans=1,sus=0,ddd=0;
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++)
	{
		v[i]=v[i-1];
		if(!s[i])v[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i])
		{
			ddd++;
			if(!sus)sus=i;
			else
			{
				kk=0;
				while(c[j]<=v[i] and j<=n)
				{
					j++;
					kk++;
				}
				ans*=kk;
				sus=i;
			}
		}
	}if(j<n)ans*=n-j;
	if(ddd<m)cout<<0;
	else cout<<ans;
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<st.size();i++)
	{
		s[i+1]=st[i]-'0';
		if(s[i+1])sum++;
	}
	ac1();
	return 0;
}
