#include<bits/stdc++.h>
using namespace std;
int n,m,s[500005],c[1500000],pre[500005],tot=0,ans=0,now=0;
struct node
{
	int start;
	int end;
}t[100000005];
bool cmp(node a,node b)
{
	return  a.end<b.end;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		pre[i]=pre[i-1]^s[i];
		int need=m^pre[i];
		if(c[need]||!need)
		{
			node d;
			d.start=c[need]+1;
			d.end=i;
			t[++tot]=d;
		}
		c[pre[i]]=i;
	}
	sort(t+1,t+1+tot,cmp);
	for(int i=1;i<=tot;i++)
	{
		if(t[i].start>now)
		{
			ans++;
			now=t[i].end;
		}
	}
	cout<<ans;
	return 0;
}