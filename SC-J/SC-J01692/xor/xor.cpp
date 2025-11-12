#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
	long long l,r;
};
long long n,k,a[N],s[N],pos[10][10];
vector<node> q;
bool check(long long x)
{
	long long maxx=-0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<q.size();i++)
	{
		long long cnt=0;
		for(int j=0;j<q.size();j++)
			if(q[j].r<q[i].l||q[j].l>q[i].r) cnt++;
		maxx=max(maxx,cnt);
		if(maxx>=x) return true;
	}
	if(maxx>=x) return true;
	else return false; 
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(k==(s[j]^s[i-1])) q.push_back({i,j});
	long long l=0,r=n;
	while(l<r)
	{
		long long mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<l;
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/