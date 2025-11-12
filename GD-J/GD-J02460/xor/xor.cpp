//60 pts 可调 会挂分 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int mx[N],a[N],nxt[N],s[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("hack1.in","r",stdin);
	ios::sync_with_stdio(0);cin.tie(0);
	memset(nxt,-1,sizeof(nxt));
	memset(mx,0,sizeof(mx));
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	s[0]=0;for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	int mn=n+1;
	for(int i=n;i;i--)
	{
		for(int j=i;j<=mn;j++)
		{
			if((s[j]^s[i-1])==k)
			{
				nxt[i]=j;mn=j;
				break;
			}
		}
	}
	mx[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		if(nxt[i]==-1)mx[i]=mx[i+1];
		else
		{
			mx[i]=max(mx[nxt[i]+1]+1,mx[i+1]);
		}
	}
	cout<<mx[1];
	return 0;
}
/*
4 2
2 1 0 3
*/
