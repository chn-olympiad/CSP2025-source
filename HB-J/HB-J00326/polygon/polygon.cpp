#include <bits/stdc++.h>
using namespace std;
int n;
int ans=0;
int length[5001];
void search(int tot,int maxn,int k,int num,int lastnum)
{
	if(k==num+1)
	{
		if(tot>maxn*2)
		{
			ans++;
		}
		return;
	}
	for(int i=lastnum+1;i<=n;i++)
	{
		int currmaxn=max(length[i],maxn);
		search(tot+length[i],currmaxn,k+1,num,i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(length,0,sizeof(length));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>length[i];
	}
	sort(length+1,length+1+n);
	for(int i=3;i<=n;i++)
	{
		search(0,0,1,i,0);
	}
	cout<<ans<<endl;
	return 0;
}
