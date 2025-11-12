#include<iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long i,j,n,m,t,k,g;
    long long a[10001][10001],b[10001];
    cin>>n>>m;
    for(i=1;i<=n*m;++i)
        cin>>b[i];
        k=b[1];
    for(i=1;i<=n*m;++i)
    if(b[i]<b[i+1]){swap(b[i],b[i+1];}
    t=1;j=1;
    for(i=1;i<=m;++i)
    {
        g=j;
        if(j<=n){
        for(;j<=n;++j)
        {
            a[j][i]=b[t];t++;
        }
        }
     if(g>n){
        for(;g>0;g--)
            {
               a[g][i]=b[t];t++;
            }
        }
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        if(a[i][j])==k)cout<<i<<"  "<<j<<endl;
    return 0;
}
