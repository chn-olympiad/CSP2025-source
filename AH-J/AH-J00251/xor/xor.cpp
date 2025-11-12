#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}f[500005];
int n,k,a[500005],ans;
bool pd[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int cnt,p=0;
	for(int i=1;i<=n;i++)
	{
		cnt=a[i];
		if(cnt==k)
			f[++p]={i,i};
		for(int j=i+1;j<=n;j++)
		{
			cnt^=a[j];
			if(cnt==k)
				f[++p]={i,j};
		}
	}
	for(int i=1;i<=p;i++)
		for(int j=i+1;j<=p;j++)
		{
			if(f[i].l<=f[j].l&&f[i].r>=f[j].r)
				pd[j]=1;
			else if(f[i].l>=f[j].l&&f[i].r<=f[j].r)
			{
				pd[i]=1;
				break;
			}
		}
	for(int i=1;i<=p;i++)
		if(pd[i]!=1)
			ans++;
	cout<<ans;
	return 0;
}

