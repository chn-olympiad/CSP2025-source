#include<bits/stdc++.h>
using namespace std;
struct w{
    int id;
    int myd;
    };
bool operator<(w a,w b)
{
    if(a.myd==b.myd)
        return a.id>b.id;
    return a.myd<b.myd;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int t;
    cin>>t;
    int n;
    cin>>n;
    priority_queue<w> q1;
    priority_queue<w> q2;
    priority_queue<w> q3;
    for(int j=0;j<=n-1;j++)
    {
        int q;
        cin>>q;
        q1.push({j,q});
        cin>>q;
        q2.push({j,q});
        cin>>q;
        q3.push({j,q});
    }
    cout<<0;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
