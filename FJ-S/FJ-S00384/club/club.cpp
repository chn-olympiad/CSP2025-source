#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int n;
struct Node
{
	long long q,idx;
	long long s1,s2;
}a1[N],b1[N],c1[N];
long long s[N];
long long ans;
bool cmp(Node d,Node e)
{
	if(d.q!=e.q)
		return d.q>e.q;
	else if(d.s1!=e.s1)
	{
		return d.s1<e.s1;
	}
	else return d.idx>e.idx;	
}
void solve()
{
	int all=1,bll=1,cll=1,as=0,bs=0,cs=0;
	for(int i=1;i<=n;i++)
	{
		if(a1[all].q>=b1[bll].q&&a1[all].q>=c1[cll].q)
		{
//			cout<<"qqq";
			if(a[a1[all].idx]==-1)
			{
				all++;
				i--;
				continue;
			}
			if(as==n/2)
			{
				a1[all].q=-0x3f3f3f3f;
				i--;
				continue;
			}
			ans+=a[a1[all].idx];
			a[a1[all].idx]=-1;
			b[a1[all].idx]=-1;
			c[a1[all].idx]=-1;
			as++;
			all++;
//			cout<<a1[all].idx<<endl;
//			cout<<1<<" "<<ans<<endl;
		}
		else if(b1[bll].q>=a1[all].q&&b1[bll].q>=c1[cll].q)
		{
			if(b[b1[bll].idx]==-1)
			{
				bll++;
				i--;
				continue;
			}
			if(bs==n/2)
			{
				b1[bll].q=-0x3f3f3f3f;
				i--;
				continue;
			}
			ans+=b[b1[bll].idx];
			bs++;
			a[b1[bll].idx]=-1;
			b[b1[bll].idx]=-1;
			c[b1[bll].idx]=-1;
			bll++;
//			cout<<b1[bll].idx<<endl;
//			cout<<2<<" "<<ans<<endl;
		}
		else if(c1[cll].q>=a1[all].q&&c1[cll].q>=b1[bll].q)
		{
			if(c[c1[cll].idx]==-1)
			{
				i--;
				cll++;
				continue;
			}
			if(cs==n/2)
			{
				c1[cll].q=-0x3f3f3f3f;
				i--;
				continue;
			}
//			cout<<a1[all].q<<" "<<b1[bll].q<<" "<<c1[cll].q<<endl;
			ans+=c[c1[cll].idx];
			cs++;
			a[c1[cll].idx]=-1;
			b[c1[cll].idx]=-1;
			c[c1[cll].idx]=-1;
			bll++;
//			cout<<c1[cll].idx<<endl;
//			cout<<3<<" "<<ans<<endl;
		}
	}
//	cout<<all<<' '<<bll<<' '<<cll<<endl;
//	cout<<as<<' '<<bs<<" "<<cs<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			int q1=a[i]-b[i]-c[i],q2=b[i]-a[i]-c[i],q3=c[i]-a[i]-b[i];
			a1[i]={q1,i,q2,q3};
			b1[i]={q2,i,q1,q3};
			c1[i]={q3,i,q1,q2};
		}
		sort(a1+1,a1+n+1,cmp);
//		for(int i=1;i<=n;i++) cout<<a1[i].q<<" ";
//		cout<<endl;
		sort(b1+1,b1+n+1,cmp);
//		for(int i=1;i<=n;i++) cout<<b1[i].q<<" ";
//		cout<<endl;
		sort(c1+1,c1+n+1,cmp);
//		for(int i=1;i<=n;i++) cout<<c1[i].q<<" ";
//		cout<<endl;
		solve();
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
}
