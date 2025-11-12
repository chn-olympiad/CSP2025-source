#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    int c[1000010];
    unsigned long long sum=0;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b >> c[i];
        sum+=c[i];
    }
    for(int i=1;i<=k;i++){
        int q,w,e,r,t;
        cin >> q >> w >> e >> r >> t;
    }
    sort(c+1,c+n+1);
    reverse(c+1,c+n+1);
    for(int i=1;i<=m-n+1;i++){
        sum-=c[i];
    }
    cout << sum;
    return 0;
}
