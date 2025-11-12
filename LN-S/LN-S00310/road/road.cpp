#include <bits/stdc++.h>

using namespace std;
const int N=1000001;
struct road{
    int u,v,w;
    bool con=false;
}r[N];
struct city{
    int a[N];
    int c;
    int du=0;
    bool con=false;
}b[11];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,sum=0;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>r[i].u>>r[i].v>>r[i].w;
    }
    for(int i=0;i<k;i++){
        cin>>b[i].c;
        for(int j=0;j<n;j++)cin>>b[i].a[j];
    }
    for(int i=0;i<n;i++){
        int minm,minw=10000000;
        for(int j=0;j<m;j++){
            if(r[j].u==i||r[j].v==i){
                if(r[j].w<minw){
                    minw=r[j].w;
                    minm=j;
                }
            }
        }
        r[minm].con=true;
    }
    for(int i=0;i<m;i++){
        if(r[i].con)sum+=r[i].w;
    }
    cout<<sum;
    return 0;
}
