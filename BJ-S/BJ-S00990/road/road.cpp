#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[10005],ans;
struct uct {
    int u,v,w;
}a[1000005];
bool cmp (uct x,uct y){
    return x.w < y.w;
}
int istr(int x){
    if(b[x] == x){
        return x;
    }
    b[x] = istr(b[x]);
    return b[x];
}
void hb(int x,int y){
    int i = istr(x);
    int j = istr(y);
    if(i == j){
        b[i] = j;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        b[i] = i;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    if(k == 0){
        sort(a+1,a+m+1,cmp);
        int sum = 0;
        for(int i=1;sum < n-1;i++){
            if(istr(a[i].u) != istr(a[i].v)){
                hb(a[i].u,a[i].v);
                ans += a[i].w;
                sum++;
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
