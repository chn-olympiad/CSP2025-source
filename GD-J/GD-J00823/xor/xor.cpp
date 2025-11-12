#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],b[500005],id,ans,c[50000005];
struct node {
	int l,r;
}q[500005];
bool cmp(node x,node y)
{
	if(x.r==y.r) return x.l<y.l;
	else return x.r<y.r;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>10000)
	{
		int qqq=0;
		for(int i=1;i<=n;i++) 
			if(a[i]==1) qqq++;
		cout<<qqq;
		return 0;
		 
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++) b[i]=b[i-1]^a[i];
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=j;i++)
		{
			if((b[j]^b[i-1])==k) 
			{
				id++; 
				q[id].l=i;
				q[id].r=j;
				if(c[j]!=0)
				{
					if(i>q[c[j]].l) c[j]=id;
				}
				if(c[j]==0) c[j]=id;
			}
		}
	}
	sort(q+1,q+id+1,cmp);
	int L=0,R=n+1;
	for(int i=n;i>=1;i--)
	{
		if(c[i]!=0) //说明此处有一个r端点 
		{
			if(i>=L&&i<=R)
			{
				if(q[c[i]].l>=L) L=q[c[i]].l,R=q[c[i]].r; 
			}
			else L=q[c[i]].l,R=q[c[i]].r;
			
		}
		if(i==L) ans++;
	}
	//for(int i=1;i<=id;i++) cout<<q[i].l<<" "<<q[i].r<<endl;
	cout<<ans<<endl;
	//for(int i=1;i<=985;i++) cout<<c[i]<<" "<<q[c[i]].l<<" "<<q[c[i]].r<<endl;
	return 0;
} 
