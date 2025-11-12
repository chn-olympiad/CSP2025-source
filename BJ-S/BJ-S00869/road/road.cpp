#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> u,v,w,c;
vector<vector<int>> a;
int cost[10000][10000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int tmp;
        cin >> tmp;
        u.push_back(tmp);
        cin >> tmp;
        v.push_back(tmp);
        cin >> tmp;
        w.push_back(tmp);
    }
    for(int i=0;i<k;i++)
    {
        int tmp;
        vector<int> tmpv;
        cin >> tmp;
        c.push_back(tmp);
        for(int j=0;j<n;j++)
        {
            cin >> tmp;
            tmpv.push_back(tmp);
        }
        a.push_back(tmpv);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cost[i][j]=1000000000;
            if(i==j)
            {
                cost[i][j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        ans += w[i];
    }
    int sig=0;
    while(sig!=0){
    sig=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (cost[u[i]][j]+cost[j][v[i]]<w[i])
            {
                ans -= w[i];
                goto br;
            }
        }
        cost[u[i]][v[i]]=w[i];
        sig++;
        br:;
    }
    }

    cout << ans;
    return 0;
}
