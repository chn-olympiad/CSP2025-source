#include<bits/stdc++.h>
using namespace std;
int a[500010];
int sx[500010];
struct lr{
	int l;
	int r;
};
lr pos[500010];
bool cmp(lr lll, lr rrr)
{
	if(lll.r<rrr.r)
	{
		return 1;
	}
	if(lll.r==rrr.r)
	{
		return lll.r-lll.l<rrr.r-rrr.l;
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		sx[i]=sx[i-1]^a[i];
		//cout<<sx[i]<<" ";
	}
	int t=1;
	for(int i=1;i<=n;i++)
	{
		if(sx[i]==k)
		{
			pos[t].l=1;
			pos[t].r=i;
			t++;
			//cout<<1<<" "<<i<<endl;
		}
		for(int j=1;j+1<=i;j++)
		{
			if(sx[j]==(sx[i]^k))
			{
				pos[t].l=j+1;
				pos[t].r=i;
				t++;
			}
		}
		//cout<<e[sx[i]^k]<<" ";
	}
	//cout<<t;
	
	sort(pos+1,pos+t,cmp);
	int cnt=1;
	int v=1;
	for(int i=2;i<t;i++)
	{
		if(pos[i].l>pos[v].r)
		{
			cnt++;
			v=i;
		}
	}
	cout<<cnt;
	return 0;
}
