#include<bits/stdc++.h>
using namespace std;
int f[5010];
int a[5010];
int sum[5010],maxn[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    f[1]=0,f[2]=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum[1]=a[1],maxn[1]=a[1];
    sum[2]=sum[1]+a[2],maxn[2]=max(maxn[1],a[2]);
    sum[3]=sum[2]+a[3],maxn[3]=max(maxn[2],a[3]);
    if(sum[3]>2*maxn[3]){
        f[3]=1;
    }
    else{
        f[3]=0;
    }
    cout<<f[3];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
