#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long sum;
struct road{
    int u,v,w;
}a[1000005];
struct village{
    int c;
    int x[1000005];
}b[15];
bool cmp(road a,road b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>b[i].c;
        for(int j=1;j<=n;j++){
            cin>>b[i].x[j];
        }
    }
    sort(a+1,a+m+1,cmp);
    if(m+1==n){
        m++;
    }
    for(int i=1;i+1<=m;i++){
        sum+=a[i].w;
    }
    cout<<sum;
    return 0;
}
