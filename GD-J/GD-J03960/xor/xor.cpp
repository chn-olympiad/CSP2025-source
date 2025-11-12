#include<bits/stdc++.h>
using namespace std;
int n,k,a[signed(5e5+10)],s[signed(5e5+10)],cnt,f[signed(5e5+10)];
struct node {
	int l,r;
}p[signed(1e6+10)];
bool cmp(node a,node b)
{
	return a.r-a.l==b.r-b.l?a.l<b.l:a.r-a.l<b.r-b.l;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((s[j]^s[i-1] )== k) 
			{
				p[++cnt].l=i,p[cnt].r=j;
			}
		}
	}
	sort(p+1,p+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int fl=0;
		for(int j=p[i].l;j<=p[i].r;j++)
		{
			if(f[j] == 1){
				fl=1;
				break;
			}
		}
		if(fl==1) continue; 
		for(int j=p[i].l;j<=p[i].r;j++)
		{
			f[j]=1;
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
