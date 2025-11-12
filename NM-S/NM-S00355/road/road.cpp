#include <bits/stdc++.h>
using namespace std;
int a[10005],u[10005],v[10005],w[10005];
int c;
int sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=n+1;i++){
        int b;
        cin>>b;
        if(i==1) c=b;
        else a[i-1]=b;
    }

    for(int i=1;i<=m;i++){
        sum+=a[i];
    }

    cout<<sum;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
