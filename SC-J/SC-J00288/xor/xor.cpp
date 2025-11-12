#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500010];
int xr(int x,int y)
{
	string xx,yy,b;
	int t=1,cnt=0;
	while(x)
	{
		xx+='0'+x%2;
		x/=2;
	}
	while(y)
	{
		yy+='0'+y%2;
		y/=2;
	}
	for(int i=0;i<min(xx.size(),yy.size());i++)
	if(xx[i]!=yy[i]) b+='1';
	else if(xx[i]==yy[i]) b+='0';
	for(int i=min(xx.size(),yy.size());i<max(xx.size(),yy.size());i++)
	b+='1';
	for(int i=0;i<b.size();i++)
	{
		if(b[i]=='1') cnt+=t;
		t*=2;
	}
	return cnt;
}
bool check(int l,int r)
{
	int cnt;
	if(l==r)
	{
		if(a[l]==k) return true;
		return false;
	}
	cnt=xr(l+1,l);
	for(int i=l+2;i<=r;i++)
		cnt=xr(cnt,a[i]);
	if(cnt==k) return true;
	return false;
}
int main()
{
	freopen("xor5.in","r",stdin);
	freopen("xor5.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		if(a[i]==1) ans++;
	}
	else if(k==0)
	{
		for(int i=1;i<=n;i++)
		if(a[i]==0) ans++;
	}
	else
	{
		for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
		{
			if(check(l,r))
			{
				ans++;
				l=r+1;
			}
		}
	}
	cout<<ans;
}