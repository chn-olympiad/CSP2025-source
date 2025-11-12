#include <iostream>
using namespace std;
int w[10005],sum=0;
int main()
{
    freopen("road in","r",stdin);
    freopen("road out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
        sum+=w[i];
    }
    cout<<sum;
    return 0;
}
