#include<bits/stdc++.h> 
using namespace std;
const int INF=1e5+5;
int n,m,x,y,z,ans;
int vi[5];
priority_queue<int> a,b,c;
void solve(int w,int k)
{
	ans=ans+w;
	vi[k]++;
	return ;
}
void f(int k)
{
	if(k==1) a.pop();
	if(k==2) b.pop();
	if(k==3) c.pop();
}
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>m;
	while(m--)
	{
		vi[1]=0,vi[2]=0,vi[3]=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			a.push(x);
			b.push(y);
			c.push(z);
		}
		for(int i=1;i<=n;i++)
		{
			int aa=a.top(),ai=1;
			int bb=b.top(),bi=2;
			int cc=c.top(),ci=3;
			if(bb<cc) swap(bb,cc),swap(bi,ci);
			if(aa<bb) swap(aa,bb),swap(ai,bi);
			if(vi[ai]<n/2)
			{
				vi[ai]++;
				ans=ans+aa;
				f(ai);
				continue;
			}
			if(vi[bi]<n/2)
			{
				vi[bi]++;
				ans=ans+bb;
				f(bi);
				continue;
			}
			if(vi[ci]<n/2)
			{
				vi[ci]++;
				ans=ans+cc;
				f(ci);
				continue;
			}
		}
		while(!a.empty()) a.pop();
		while(!b.empty()) b.pop();
		while(!c.empty()) c.pop();
		cout<<ans<<endl;
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
