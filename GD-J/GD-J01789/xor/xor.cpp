#include<bits/stdc++.h>
using namespace std;
#define N 500010
//bool Mst;

int n,k,a[N];
int last[3000010];
int sum[N];

struct node
{
	int l,r;
}q[N];int qlen=0;
bool operator<(node n1,node n2)
{
	return n1.r<n2.r;
}

//bool Med;
signed main()
{
//	printf("%.2lf M",1.0*(&Mst-&Med)/1024/1024);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
//	freopen("xor6.in","r",stdin);
	
	cin>>n>>k;
	int mxai=0;
	for(int i=1;i<=n;i++)cin>>a[i],mxai=max(mxai,a[i]);
	for(int i=0;i<=mxai;i++)last[i]=-1;
	sum[0]=0;last[0]=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]^a[i];
		int x=k^sum[i];
		if(last[x]!=-1)q[++qlen]=(node){last[x]+1,i};
		last[sum[i]]=i;
	}
	sort(q+1,q+qlen+1);
	
	int mxr=0,ans=0;
	for(int i=1;i<=qlen;i++)
	{
//		cout<<q[i].l<<' '<<q[i].r<<'\n';
//		for(int j=q[i].l;j<=q[i].r;j++)cout<<a[j]<<' ';cout<<'\n';
		
		if(q[i].l>mxr)ans++,
//					cout<<i<<' '<<mxr<<' '<<q[i].l<<' '<<q[i].r<<'\n';
		mxr=max(mxr,q[i].r);
	}
	cout<<ans<<'\n';
	
	
	return 0;
}
