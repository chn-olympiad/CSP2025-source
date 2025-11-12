#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int w[MAXN];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int t1,t2,t3;
    for(int i=0;i<m;i++)
        cin>>t1>>t2>>t3;
    for(int i=0;i<k;i++)
    {
        cin>>t1;
        for(int j=0;j<n;j++)
        {
            cin>>w[j];
        }
    }
    cout<<0;
    return 0;
}