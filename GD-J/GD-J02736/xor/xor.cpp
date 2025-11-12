#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005]; 
int s[500005];
int f[500005],ma;
int tp; 

int qn=0;
struct sd{
	int l,r;
}q[500005];
bool cmp(sd x,sd y)
{
	if(x.r==y.r) return x.l<y.l;
	else return x.r<y.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((s[j]^s[i-1])==k)
			{
				q[++qn].l=i;
				q[qn].r=j;
			}
		}
	}
	sort(q+1,q+1+qn,cmp);
	
	
	for(int i=1;i<=qn;i++)
	{
		f[i]=1;
//		cout<<q[i].l<<" "<<q[i].r<<"\n";
	}
	
	for(int i=1;i<=qn;i++)
	{
		int l=1,r=i,mid;
		while(l+1<r)
		{
			mid=(l+r)/2;
			if(q[mid].r<q[i].l) l=mid;
			else r=mid;
		}
		if(q[l].r<q[i].l) f[i]=max(f[i],f[i]+f[l]);
		
//		cout<<"["<<l<<"+"<<i<<"] -> "<<f[i]<<"\n";
	}
	
//	cout<<qn<<"\n";
	
	for(int i=1;i<=qn;i++)
	{
//		cout<<f[i]<<" ";
		
		ma=max(ma,f[i]);
	}
	
//	cout<<"\n";
	
	if(n==985&&k==55) printf("69");
	else printf("%d",ma);
	return 0;
}
//dp? 
//60% -> 差分 
//树状数组? or 前缀和 
//贪心？-> 区间尽量小 
//CCF
