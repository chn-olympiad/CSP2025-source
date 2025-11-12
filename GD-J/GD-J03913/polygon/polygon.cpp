#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010],ans,c[5010];
void dg(int now,int nn,int sum,int ma,int x)
{
	if(now==nn+1)
	{if(sum>ma*2) ans++;return;}
	for(int i=x+1;i<=n;i++)
	if(b[i]==0)
	{
		b[i]=1;
		dg(now+1,nn,sum+a[i],max(ma,a[i]),i);
		b[i]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++) dg(1,i,0,0,0);
	cout<<ans;
	return 0;
}
