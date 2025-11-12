#include<bits/stdc++.h>
using namespace std;
using pr=pair<long long,long long>;
constexpr long long N=1e5,M=1e5,V=1e18;
long long n,m;
pr a[5][N+5];
bitset<N+5> is_chs;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
//	int d[5]{};
	for(;T>0;T--)
	{
		cin>>n;
		long long ans=0;
		priority_queue<int,vector<int>,greater<int>> q[4];
//		vector<pr> vc;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[1][i]=make_pair(x,i);
			a[2][i]=make_pair(y,i);
			a[3][i]=make_pair(z,i);
//			auto *mxv=a[1];
//			if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]) mxv=a[1];
//			if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i]) mxv=a[2];
//			if(a[3][i]>=a[1][i]&&a[3][i]>=a[2][i]) mxv=a[3];
//			auto v=mxv-a[1],v_1=a[v][i].first,
//			v_2=*max_element(vector<int>{x,y,z},2),
//			v_3=*max_element(vector<int>{x,y,z},3);
//			int p=0;
//			if(v_1>=x&&y>=v_3) p=1;
//			if(v_1>=)
			vector<pr> tmp{{x,1},{y,2},{z,3}};
			sort(tmp.begin(),tmp.end(),greater<pr>());
			int v=tmp[0].second,v_1=tmp[0].first,v_2=tmp[1].first,
			v2=tmp[1].first;
			if(q[v].size()+1<=n/2) q[v].push(v_1-v_2),ans+=v_1;
			else 
			{
				if(q[v].top()<v_1-v_2)
				{
					ans=ans-q[v].top()+v_1;
					q[v].pop();q[v].push(v_1-v_2);
				}
				else 
				{
					ans+=v_2;
				}
			}
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
//It has wasted my 2 hours qwq
//2 vagetables TAT
