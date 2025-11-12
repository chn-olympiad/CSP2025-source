#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct nn{
    int u,v,w;
}a[10910101];
int c[11][1001],qw[10001];
bool cmp(nn a,nn b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for(int i=1;i<=k;i++){
        cin >> qw[i];
        for(int j=1;j<=n;j++){
            cin >> c[i][j];
        }
    }
    sort(a+1,a+1+n,cmp);
    int sum=0;
    int qw[11001]={};
    int o=0;
    for(int i=1;i<=n;i++){
        if(qw[a[i].u]>=2||qw[a[i].v]>=2){
            continue;
        }else{
            sum+=a[i].w;
            o++;
        }
        if(o==n-1){
            break;
        }
    }
    cout << sum;
}
