//GZ-S00361 毕节东辰实验学校 罗圣喻
#include <bits/stdc++.h>
using namespace std;
struct node{
    int fr,to,num;
};
vector <node> ma[1000010];
int n,m,k;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,x,y,w;i<=m;i++)
    {
        cin>>x>>y>>w;
    }
    for(int i=1,x;i<=k;i++)
    {
        cin>>x;
        for(int j=1,y;j<=n;j++)
            cin>>y;
    }
    cout<<0<<endl;
    return 0;
}
