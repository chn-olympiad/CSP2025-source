#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],cnt,m;
bool f[N];
int yh(int x,int y)
{
	int b[N],c[N],ans=0,num=0,t=0;
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	while(x!=0)
	{
		b[++ans]=x%2;
		x/=2;
	}
	while(y!=0)
	{
		c[++num]=y%2;
		y/=2;
	}
	ans=max(ans,num);
	for(int i=ans;i>=1;i--)
	{
		if(c[i]==b[i]) c[i]=1-c[i];
		else if((c[i]==1&&b[i]==0)||(c[i]==0&&b[i]==1)) c[i]=1;
	}
	for(int i=ans;i>=1;i--)
	{
		t=t+c[i]*pow(2,ans-i);
	}
	return t;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	if(cnt==n)
	{
		if(m==1)
		{
			cout<<n;
			return 0;
		}
		if(n%2==0) cout<<cnt/2;
		else cout<<(cnt-1)/2;
		return 0;
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==m)
		{
			cnt++;
			f[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(f[j]==1||f[i]==1) break;
			x=yh(x,a[j]);
			cout<<x<<'\n';
			if(x==m) 
			{
				cnt++;
				for(int xs=i;xs<=j;xs++) f[xs]=1;
				break;
			}
			else if(x>m) break;
		}
	}
	cout<<cnt;
    return 0;
}
