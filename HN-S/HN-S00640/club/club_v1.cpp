#include<bits/stdc++.h>
using namespace std;
using pr=pair<long long,long long>;
constexpr long long N=1e5,M=1e5,V=1e18;
long long n,m;
pr a[N+5],b[N+5],c[N+5];
bitset<N+5> is_chs;
//struct pr
//{
//	int x,y,z;
//	pr(int a,int b,int c):x(a),y(b),z(c){}
//	pr():pr(0,0,0){}
//	friend bool operator< (pr a,pr b)
//	{
//		if(a.x!=b.x) return a.x>b.x;
//		if(a.y!=b.y) return a.y>b.y;
//		return a.z>b.z;
//	}
//};'
long long chk(pr r[],pr r1[],pr r2[])
{
	long long ret=0;
	for(int i=1;i<=n;i++) is_chs[i]=0;
	for(int i=1;i<=n/2;i++)
	{
		ret+=r[i].first;
		is_chs[i]=1;
	}
	int cnt=0;
	for(int i=1,j=1;cnt<n/2;cnt++)
	{
		for(;is_chs[r1[i].second];i++);
		for(;is_chs[r2[j].second];j++);
		if(i>n||r2[j].first>=r1[i].first)
		{
			ret+=r2[j].first;
			is_chs[r2[j].second]=1;	
		}
		if(j>n||r2[j].first<r1[i].first)
		{
			ret+=r1[i].first;
			is_chs[r1[i].second]=1;	
		}  
	}
	return ret;
}
int main()
{
	freopen("club2.in","r",stdin);
//	freopen("club.out","w",stdout);
	int T;cin>>T;
	for(;T>0;T--)
	{
		cin>>n;
//		vector<pr> vc;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[i]=make_pair(x,i);
			b[i]=make_pair(y,i);
			c[i]=make_pair(z,i);
//			vc.push_back({x,i,1});
//			vc.push_back({y,i,2});
//			vc.push_back({z,i,3});
		}
//		sort(vc.begin(),vc.end());
		sort
		long long w[5]{},ans=0;
		for(int i=1;i<=n;i++) is_chs[i]=0;
		for(const auto &i:vc)
		{
			if(is_chs[i.y]||w[i.z]+1>n/2) 
				continue;
			ans+=i.x;w[i.z]++;
			is_chs[i.y]=1;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
