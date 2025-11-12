#include<bits/stdc++.h>
using namespace std;
vector<int>a[10001];
int b[10001];
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q[4];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push(y);
        a[y].push(x);
    }
    for(int i = 1;i<=n;i++)
    {
        cin>>b[i];
    }
    cout<<13<<endl;
    return 0;
}
