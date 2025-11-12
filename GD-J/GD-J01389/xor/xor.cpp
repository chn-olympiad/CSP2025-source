#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,cnt=0;
struct qj
{
	int l,r;
}b[500005];
bool cmp(qj a,qj b)
{
	if(a.l==b.l)
		return a.r<b.r;
	return a.l<b.l;
}
void f(int l,int r,int s) 
{
	if(l>r) return;
	if(s==k) b[++cnt]={l,r};
	f(l+1,r,s^a[l]);
	f(l,r-1,s^a[r]);
}
int d(int l,int r)
{
	
	int s=0;
	for(int i=1;i<=cnt;i++)
	{
		if(b[i].l>l and b[i].r<r)
			s=max(d(b[i].r,r)+1,s);
	}
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int s=0;
	for(int i=1;i<=n;i++)
	{
		s^=a[i];
	}
	f(1,n,s);
	for(int i=1;i<=cnt;i++)
	{
		for(int j=i+1;j<=cnt;j++)
		{
			if(b[i].l>=b[j].l and b[i].r<=b[j].r)
			{
				b[j]=b[cnt];
				cnt--;
			}
			if(b[i].l<=b[j].l and b[i].r>=b[j].r)
			{
				b[i]=b[cnt];
				cnt--;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	cout<<d(0,n+1)<<endl;
	return 0;
} 
