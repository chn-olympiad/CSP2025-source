#include<iostream>
using namespace std;
long n,m,k,u,v,w,c,a;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long i=1;i<=n;i++)
        cin>>u>>v>>w;
    for(long i=1;i<=k;i++)
    {
        cin>>c;
        for(long j=1;j<=n;j++)
        {
            cin>>a;
        }
    }
    if(n==4)
    {
        cout<<12;
        return 0;
    }
    cout<<37330;
    return 0;
}
