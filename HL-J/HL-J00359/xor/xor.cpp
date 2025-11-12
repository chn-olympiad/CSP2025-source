#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],lk2=0,t[1100005][2],lst[1100005],cnt=0,b[500005],kk,x;
bool k2[30],x2[30];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	  a[i]=a[i]^a[i-1];
	kk=k;
	int nx=0;
	for(int i=1;i<=20;i++)
	{
		k2[i]=kk&1;
		kk>>=1;
	}
	for(int i=0;i<=n;i++)
	{
		x=a[i];
		for(int j=1;j<=20;j++)
		{
			x2[j]=x&1;
			x>>=1;
		}
		bool ynn=1;
		nx=0;
		for(int j=1;j<=20;j++)
		{
			bool c=(x2[j]^k2[j]);
			if(t[nx][c]==0)
			{
			  ynn=0;
			  break;
			}
			nx=t[nx][c];
		}
		if(ynn)
		{
		  b[i]=lst[nx]+1;
		}
		else
		  b[i]=0;
		nx=0;
		for(int j=1;j<=20;j++)
		{
			if(t[nx][x2[j]]==0)
				t[nx][x2[j]]=++cnt;
			nx=t[nx][x2[j]];
		}
		lst[nx]=i;
	}
	int ans=0,R=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>R)
		{
			ans++;
			R=i;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
