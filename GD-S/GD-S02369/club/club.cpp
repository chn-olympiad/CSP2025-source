#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int ans,n,A,B,C,cnt[3],vis[3];
struct id{
	int mx,smx,mn,mxid,smxid,id,mnid;
}a[1000001],b[500001];
bool cmp1(id x,id y)
{
	int c1=x.mx-x.smx,c2=x.smx-x.mn;
	int d1=y.mx-y.smx,d2=y.smx-y.mn;
	if(c1==d1) return x.mx<y.mx;
	return c1<d1;
}
bool cmp2(id x,id y)
{
	int c1=x.mx-x.smx,c2=x.smx-x.mn;
	int d1=y.mx-y.smx,d2=y.smx-y.mn;
	if(c2==d2) return x.smx<y.smx;
	return c2<d2;
}
void man()
{
	ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	vis[0]=vis[1]=vis[2]=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>A>>B>>C;
		int mx=0,smx=0,mn=1e9;
		mx=max(max(A,B),C);
		mn=min(C,min(A,B));
		if(mx==A) 
		{
			smx=max(B,C);
			a[i].mxid=0;
			if(smx==B) a[i].smxid=1,a[i].mnid=2;
			else a[i].smxid=2,a[i].mnid=1;
		}
		if(mx==B) 
		{
			smx=max(A,C),a[i].mxid=1;
			if(smx==A) a[i].smxid=0,a[i].mnid=2;
			else a[i].smxid=2,a[i].mnid=0;
		}
		if(mx==C) 
		{
			smx=max(A,B),a[i].mxid=2;
			if(smx==B) a[i].smxid=1,a[i].mnid=0;
			else a[i].smxid=0,a[i].mnid=1;
		}
//		a[i].cha=mx-smx;
//		ans+=mx;
		a[i].smx=smx,a[i].mx=mx,a[i].mn=mn;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i].mx<<" "<<a[i].smx<<endl;
//	}
	sort(a+1,a+1+n,cmp1);
//	cout<<b[1]<<endl;
	int tot=0,tar=0;
	for(int i=n;i>=1;i--)
	{
//		cout<<(cnt[a[i].mxid]+1)<<" "<<ans<<" "<<a[i].mx<<" "<<a[i].smx<<" "<<a[i].mn<<" "<<a[i].mxid<<endl; 
		if(!vis[a[i].mxid])
		{
			ans+=a[i].mx,cnt[a[i].mxid]++;
			if(cnt[a[i].mxid]>=(n/2)) vis[a[i].mxid]=1;
		}
		else b[++tot]=a[i];	
	}
	sort(b+1,b+1+tot,cmp2);
	int tar2=0;
	for(int i=tot;i>=1;i--)
	{
		if(!vis[b[i].smxid])
		{
			ans+=b[i].smx,cnt[b[i].smxid]++;
			if(cnt[b[i].smxid]>=(n/2)) vis[b[i].smxid]=1;
		}
		else ans+=b[i].mn;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) man();
}
