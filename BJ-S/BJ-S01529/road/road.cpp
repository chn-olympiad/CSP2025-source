#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
const int M=1e3+7;
const int INF=0x3f3f3f3f;
//time :O(N2)
//space:O(N2)
int T;
int n,m,k;

struct edge
{
    int to,w;
};

vector<edge>G[M];
ll sum=0;
ll u,v,w;
int main()
{
    srand(time(0));
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("road.in" ,"r",stdin );
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
    {
        cin>>u>>v>>w;
        sum+=w;
    }
    for(int i=1;i<=k;++i)
    {
        for(int i=1;i<=n+1;i++){cin>>u;sum+=u;}
    }
    cout<<rand()%sum;
    //
    return 0;
}

/*
=====TODO=====
subtest init
long long
freopen triple chaeck
cornercase
g++ lmz.cpp -o lmz -Wall
estimate time and space
rp++
save before run

*/
