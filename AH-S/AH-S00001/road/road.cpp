#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[20],a[20];
int fee(int sum)
{
    cin>>n,m,k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=i;j<=n;j++){
            cin>>a[i];
        }
    }
    for(int i=1;i<=n;i++){
        if((k<=5)&&(c[i]==0)){
            a[i]==0;
        }
        else if((k<=10)&&(c[i]==0)){
            a[i]==0;
        }
    }
    for(int i=1;i<=n;i++){
        if((u[i]&v[i])!=0){
            sum=w[i]+c[i]+a[i];
        }
        long long min=999999999999;
        if(sum<min){
            min=sum;
        }
    }
    return sum;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=n;i++){
        fee(i);
    }
    return 0;
}
