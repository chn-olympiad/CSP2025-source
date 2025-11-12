//begin½ÏÐ¡ 
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn=1e5+10;
int n,ans,sum,sumz1,sumz2,sumf;
pii a[maxn];
int b[maxn],c[maxn],d[maxn];
multiset<int> stz11,stz12,stz21,stz22,stf,stff;
inline bool cmp(pii x,pii y)
{
	return x.first-x.second>y.first-y.second;
}
inline void addz1()
{
	int x=*stz12.rbegin();
	stz12.erase(stz12.find(x));
	stz11.insert(x),sumz1+=x;
}
inline void delz1()
{
	int x=*stz11.begin();
	stz11.erase(stz11.find(x));
	stz12.insert(x),sumz1-=x;
}
inline void addz2()
{
	int x=*stz22.rbegin();
	stz22.erase(stz22.find(x));
	stz21.insert(x),sumz2+=x;
}
inline void delz2()
{
	int x=*stz21.begin();
	stz21.erase(stz21.find(x));
	stz22.insert(x),sumz2-=x;
}
inline void addf()
{
	int x=*stff.rbegin();
	stff.erase(stff.find(x));
	stf.insert(x),sumf+=x;
}
inline void delf()
{
	int x=*stf.begin();
	stf.erase(stf.find(x));
	stff.insert(x),sumf-=x;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n,sum=0,ans=-2e9,sumz1=sumz2=sumf=0,stz11.clear(),stz12.clear(),stz21.clear(),stz22.clear(),stf.clear(),stff.clear();
		for(int i=1,x;i<=n;i++) cin>>x>>a[i].first>>a[i].second,sum+=x,a[i].first-=x,a[i].second-=x;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
			if(a[i].second>=0) stz21.insert(a[i].second),sumz2+=a[i].second;
			else stf.insert(a[i].second),sumf+=a[i].second;
		while(stz21.size()>n/2) delz2();
		while(stf.size()+stz21.size()>n/2) delf();
		ans=max(ans,sumz1+sumz2+sumf);//,cout<<sumz1<<' '<<sumz2<<' '<<sumf<<endl;
		for(int i=1;i<=n;i++)
		{
			if(stf.count(a[i].second)) stf.erase(stf.find(a[i].second)),sumf-=a[i].second;
			else if(stff.count(a[i].second)) stff.erase(stff.find(a[i].second));
			else if(stz21.count(a[i].second)) stz21.erase(stz21.find(a[i].second)),sumz2-=a[i].second;
			else stz22.erase(stz22.find(a[i].second));
			if(a[i].first>=0) stz11.insert(a[i].first),sumz1+=a[i].first;
			else stf.insert(a[i].first),sumf+=a[i].first;
			while(stz11.size()>n/2) delz1();
			while(stz11.size()<n/2&&stz12.size()) addz1();
			while(stz21.size()>n/2) delz2();
			while(stz21.size()<n/2&&stz22.size()) addz2();
			while(stz11.size()+stz21.size()+stf.size()>n/2&&stf.size()) delf();
			while(stz11.size()+stz21.size()+stf.size()<n/2&&stff.size()) addf();
			ans=max(ans,sumz1+sumz2+sumf);//,cout<<sumz1<<' '<<sumz2<<' '<<sumf<<endl;
		}
		cout<<ans+sum<<endl;
	}
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
