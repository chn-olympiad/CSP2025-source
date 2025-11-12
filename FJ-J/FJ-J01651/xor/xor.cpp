#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],pos[2100000],x[500001],cnt=0,la=0,s=0;bool bj;
struct note{
	int l,r;
}qj[500001];
bool cmp(note i,note j)
{
	if(i.r==j.r)
		return i.l<j.l;
	return i.r<j.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		x[i]=x[i-1]^a[i],bj=0;
		if(a[i]==k)
			cnt++,qj[cnt].l=qj[cnt].r=i,bj=1;
		if(pos[x[i]^k]>0&&bj==0)
			cnt++,qj[cnt].l=pos[x[i]^k]+1,qj[cnt].r=i,bj=1;
		if(x[i]==k&&bj==0)
			cnt++,qj[cnt].l=1,qj[cnt].r=i;
		pos[x[i]]=i;
	}
	sort(qj+1,qj+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		if(qj[i].l>la)
			s++,la=qj[i].r;
	cout<<s;
	return 0;
}
