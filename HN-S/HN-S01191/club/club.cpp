#include<bits/stdc++.h>

const int N=1e5;

int a[N+5][3];

std::multiset<int>cost[3];

void sol()
{
    cost[0].clear(),cost[1].clear(),cost[2].clear();

    int n;
    std::cin>>n;

    for(int i=1;i<=n;++i)
        std::cin>>a[i][0]>>a[i][1]>>a[i][2];

    int ans=0,sum[3]{};

    for(int i=1;i<=n;++i)
    {
        if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
        {
           ++sum[0];ans+=a[i][0];
           cost[0].insert(a[i][0]-std::max(a[i][1],a[i][2]));
        }
        else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])
        {
            ++sum[1];ans+=a[i][1];
            cost[1].insert(a[i][1]-std::max(a[i][0],a[i][2]));
        }
        else
        {
            ++sum[2];ans+=a[i][2];
            cost[2].insert(a[i][2]-std::max(a[i][0],a[i][1]));
        }
    }

    for(int i=0;i<3;++i)
    {
        while(sum[i]>n/2)
        {
            --sum[i];
            ans-=(*cost[i].begin());
            cost[i].erase(cost[i].begin());
        }
    }
    std::cout<<ans<<'\n';
}

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);

	int t;
    std::cin>>t;
    while(t--)sol();
	return 0;
}
/*
有人记迷惑行为吗？

//freopen feropen froepen genshin 
#define int long long mian

luogu:1026052
*/