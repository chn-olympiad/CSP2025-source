#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long p1=1000000007,p2=1000000009,base=211,mod=399499;
long long i,j,n,q,ls[210000],lt1[210000],lt2[210000],ans[210000],sl[210000],sr[210000],swh[210000],tl[210000],tr[210000],twh[210000];
long long h1[400000],h2[400000],cnt1[400000],cnt2[400000],*wh1[400000],*wh2[400000],w1,w2,ltop=1,rtop=1,top;
long long ldfn[5500000],rdfn[5500000],ldfr[5500000],rdfr[5500000],ll[500000],rr[500000],tt[500000],vv[500000],pt[500000],px[500000],numl[500000],numr[500000],tree[22000000];
int ltree[5500000][26],rtree[5500000][26];
char in[6000000],*s1[210000],*s2[210000],*t1[210000],*t2[210000];
long long add(long long v1,long long v2)
{
	long long k=(v1*p2+v2)%mod;
	while(h1[k]!=-1)
	{
		if(h1[k]==v1&&h2[k]==v2)
		return k;
		k=(k+1)%mod;
	}
	h1[k]=v1;
	h2[k]=v2;
	return k;
}
void inl(int x,const char *s)
{
	if(*s==0)
	return;
	if(ltree[x][*s-'a']==0)
	{
		ltop++;
		ltree[x][*s-'a']=ltop;
	}
	inl(ltree[x][*s-'a'],s-1);
}
int findl(int x,const char *s)
{
	if(*s==0)
	return x;
	if(ltree[x][*s-'a']==0)
	return x;
	else
	return findl(ltree[x][*s-'a'],s-1);
}
void inr(int x,const char *s)
{
	if(*s==0)
	return;
	if(rtree[x][*s-'a']==0)
	{
		rtop++;
		rtree[x][*s-'a']=rtop;
	}
	inr(rtree[x][*s-'a'],s+1);
}
int findr(int x,const char *s)
{
	if(*s==0)
	return x;
	if(rtree[x][*s-'a']==0)
	return x;
	else
	return findr(rtree[x][*s-'a'],s+1);
}
void dfsl(int x)
{
	long long i;
	top++;
	ldfn[x]=top;
	for(i=0;i<26;i++)
	if(ltree[x][i]!=0)
	dfsl(ltree[x][i]);
	ldfr[x]=top;
}
void dfsr(int x)
{
	long long i;
	top++;
	rdfn[x]=top;
	for(i=0;i<26;i++)
	if(rtree[x][i]!=0)
	dfsr(rtree[x][i]);
	rdfr[x]=top;
}
void add(long long ll,long long rr,long long v,long long l=1,long long r=5100000,long long m=1)
{
	long long mid=(l+r)/2;
	if(l>rr||r<ll)
	return;
	if(l>=ll&&r<=rr)
	{
		tree[m]=tree[m]+v;
		return;
	}
	if(tree[m]!=0)
	{
		tree[m*2]=tree[m*2]+tree[m];
		tree[m*2+1]=tree[m*2+1]+tree[m];
		tree[m]=0;
	}
	add(ll,rr,v,l,mid,m*2);
	add(ll,rr,v,mid+1,r,m*2+1);
}
long long getv(long long x,long long l=1,long long r=5100000,long long m=1)
{
	long long mid=(l+r)/2;
	if(l>x||r<x)
	return 0;
	if(l==r)
	return tree[m];
	if(tree[m]!=0)
	{
		tree[m*2]=tree[m*2]+tree[m];
		tree[m*2+1]=tree[m*2+1]+tree[m];
		tree[m]=0;
	}
	return getv(x,l,mid,m*2)+getv(x,mid+1,r,m*2+1);
}
void solve(long long x)
{
	long long i,j1=0,j2=0;
	if(cnt1[x]==0||cnt2[x]==0)
	return;
	for(i=1;i<=cnt1[x];i++)
	inl(1,s1[wh1[x][i]]+sl[wh1[x][i]]-1);
	for(i=1;i<=cnt1[x];i++)
	inr(1,s1[wh1[x][i]]+sr[wh1[x][i]]+1);
	top=0;
	dfsl(1);
	top=0;
	dfsr(1);
	for(i=1;i<=cnt1[x];i++)
	{
		tt[i*2-1]=findl(1,s1[wh1[x][i]]+sl[wh1[x][i]]-1);
		tt[i*2]=ldfr[tt[i*2-1]]+1;
		tt[i*2-1]=ldfn[tt[i*2-1]];
	}
	for(i=1;i<=cnt1[x];i++)
	{
		ll[i*2-1]=findr(1,s1[wh1[x][i]]+sr[wh1[x][i]]+1);
		rr[i*2-1]=rdfr[ll[i*2-1]];
		ll[i*2-1]=rdfn[ll[i*2-1]];
		ll[i*2]=ll[i*2-1];
		rr[i*2]=rr[i*2-1];
		vv[i*2-1]=1;
		vv[i*2]=-1;
	}
	for(i=1;i<=cnt2[x];i++)
	{
		pt[i]=ldfn[findl(1,t1[wh2[x][i]]+tl[wh2[x][i]]-1)];
		px[i]=rdfn[findr(1,t1[wh2[x][i]]+tr[wh2[x][i]]+1)];
	}
	for(i=1;i<=cnt1[x]*2;i++)
	numl[i]=i;
	sort(numl+1,numl+cnt1[x]*2+1,[](long long a,long long b)->bool{return tt[a]<tt[b]||tt[a]==tt[b]&&a<b;});
	for(i=1;i<=cnt2[x];i++)
	numr[i]=i;
	sort(numr+1,numr+cnt2[x]+1,[](long long a,long long b)->bool{return pt[a]<pt[b]||pt[a]==pt[b]&&a<b;});
	for(i=1;i<=ltop+1;i++)
	{
		while(j1<cnt1[x]*2&&tt[numl[j1+1]]<=i)
		{
			j1++;
			add(ll[numl[j1]],rr[numl[j1]],vv[numl[j1]]);
		}
		while(j2<cnt2[x]&&pt[numr[j2+1]]<=i)
		{
			j2++;
			ans[wh2[x][numr[j2]]]=getv(px[numr[j2]]);
		}
	}
	for(i=1;i<=ltop;i++)
	for(j=0;j<26;j++)
	ltree[i][j]=0;
	ltop=1;
	for(i=1;i<=rtop;i++)
	for(j=0;j<26;j++)
	rtree[i][j]=0;
	rtop=1;
}
main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("\n%s",in);
		ls[i]=strlen(in);
		s1[i]=new char[ls[i]+3];
		s2[i]=new char[ls[i]+3];
		s1[i][0]=0;
		s2[i][0]=0;
		strcpy(s1[i]+1,in);
		scanf(" %s",s2[i]+1);
	}
	for(i=1;i<=q;i++)
	{
		scanf("\n%s",in);
		lt1[i]=strlen(in);
		t1[i]=new char[lt1[i]+3];
		t1[i][0]=0;
		strcpy(t1[i]+1,in);
		scanf("\n%s",in);
		lt2[i]=strlen(in);
		t2[i]=new char[lt2[i]+3];
		t2[i][0]=0;
		strcpy(t2[i]+1,in);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=ls[i];j++)
		if(s1[i][j]!=s2[i][j])
		break;
		if(j>ls[i])
		continue;
		sl[i]=j;
		for(j=ls[i];j>=1;j--)
		if(s1[i][j]!=s2[i][j])
		break;
		sr[i]=j;
	}
	for(i=1;i<=q;i++)
	if(lt1[i]==lt2[i])
	{
		for(j=1;j<=lt1[i];j++)
		if(t1[i][j]!=t2[i][j])
		break;
		tl[i]=j;
		for(j=lt1[i];j>=1;j--)
		if(t1[i][j]!=t2[i][j])
		break;
		tr[i]=j;
	}
	for(i=0;i<mod;i++)
	h1[i]=-1;
	for(i=1;i<=n;i++)
	if(sl[i]!=0)
	{
		w1=0;
		w2=0;
		for(j=sl[i];j<=sr[i];j++)
		{
			w1=(w1*base+s1[i][j])%p1;
			w2=(w2*base+s1[i][j])%p2;
			w1=(w1*base+s2[i][j])%p1;
			w2=(w2*base+s2[i][j])%p2;
		}
		swh[i]=add(w1,w2);
	}
	else
	swh[i]=-1;
	for(i=1;i<=q;i++)
	if(tl[i]!=0)
	{
		w1=0;
		w2=0;
		for(j=tl[i];j<=tr[i];j++)
		{
			w1=(w1*base+t1[i][j])%p1;
			w2=(w2*base+t1[i][j])%p2;
			w1=(w1*base+t2[i][j])%p1;
			w2=(w2*base+t2[i][j])%p2;
		}
		twh[i]=add(w1,w2);
	}
	else
	twh[i]=-1;
	for(i=1;i<=n;i++)
	if(swh[i]>=0)
	cnt1[swh[i]]++;
	for(i=0;i<mod;i++)
	{
		wh1[i]=new long long[cnt1[i]+1];
		wh1[i][0]=0;
	}
	for(i=1;i<=n;i++)
	if(swh[i]>=0)
	{
		wh1[swh[i]][0]++;
		wh1[swh[i]][wh1[swh[i]][0]]=i;
	}
	for(i=1;i<=n;i++)
	if(twh[i]>=0)
	cnt2[twh[i]]++;
	for(i=0;i<mod;i++)
	{
		wh2[i]=new long long[cnt2[i]+1];
		wh2[i][0]=0;
	}
	for(i=1;i<=n;i++)
	if(twh[i]>=0)
	{
		wh2[twh[i]][0]++;
		wh2[twh[i]][wh2[twh[i]][0]]=i;
	}
	for(i=0;i<mod;i++)
	solve(i);
	for(i=1;i<=q;i++)
	printf("%lld\n",ans[i]);
}
