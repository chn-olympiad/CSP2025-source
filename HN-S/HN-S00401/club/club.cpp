#include <bits/stdc++.h> 

namespace solve
{
	int n;
	std::vector<std::array<int,3>> a;
	void main()
	{
		std::cin>>n;
		a.assign(n,{0,0,0});
		for(int i=0;i<n;i++)
			std::cin>>a[i][0]>>a[i][1]>>a[i][2];
		std::sort(a.begin(),a.end(),[](const std::array<int,3>& a,const std::array<int,3>& b){
			return *std::max_element(a.begin(),a.end())>*std::max_element(b.begin(),b.end());
		});
		std::array<int,3> cnt{0,0,0};
		std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> q[3];
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			int id=std::max_element(a[i].begin(),a[i].end())-a[i].begin();
			int maxval=-1,maxid=-1;
				for(int j=0;j<3;j++)
					if(j!=id&&a[i][j]>maxval)
						maxval=a[i][j],maxid=j;
			if(cnt[id]<n/2)
			{
				cnt[id]++;
				ans+=a[i][id];
				q[id].push({a[i][id]-maxval,maxid});
			}
			else if(!q[id].empty()&&q[id].top().first<a[i][id]-maxval)
			{
				cnt[q[id].top().second]++;
				ans+=a[i][id]-q[id].top().first;
				q[id].pop();
				q[id].push({a[i][id]-maxval,maxid});
			}
			else
			{
				cnt[maxid]++;
				ans+=maxval;
			}
		}
		std::cout<<ans<<'\n';
	}
}

int main()
{
#define PROBLEM_STLVECTOR "club"
#if 1
	freopen(PROBLEM_STLVECTOR".in","r",stdin);
	freopen(PROBLEM_STLVECTOR".out","w",stdout);
#endif
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int T;
	std::cin>>T;
	while(T--) solve::main();
	return 0;
}
/*
417649
*/
