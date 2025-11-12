#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000000],qa[1000000],p=1,ans=1,jb,le,ri,mid;
map<long long,vector<long long> >b;
struct line{
	long long l,r;
}l[1000000];
long long m;
bool cmp(line a,line b)
{
	return (a.r!=b.r?a.r<b.r:a.l<b.l);
}
long long erfen(long long x,long long y)
{
	le=0,ri=b[x].size()-1;
	while(le<=ri)
	{
		mid=le+(ri-le)/2;
		if(b[x][mid]>=y)ri=mid-1;
		else le=mid+1;
	}
	return le;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;++i)cin>>a[i];
	for(long long i=1;i<=n;++i)qa[i]=qa[i-1]^a[i];
	for(long long i=1;i<=n;++i)b[qa[i]].push_back(i);
	for(long long i=0;i<n;++i)
	{
		if(b[k^qa[i]].size()>0&&b[k^qa[i]][b[k^qa[i]].size()-1]>i)
		{
			jb=erfen(k^qa[i],i+1);
			m++;
			l[m].l=i+1;
			l[m].r=b[k^qa[i]][jb];
		}
	}
	if(m==0)
	{
		cout<<0;
		return 0;
	}
	sort(l+1,l+m+1,cmp);
	for(long long i=1;i<=m;++i)
	{
		if(l[i].l>l[p].r)
		{
			ans++;
			p=i;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
