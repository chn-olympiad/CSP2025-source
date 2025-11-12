#include<bits/stdc++.h>
using namespace std;
struct Node{
    int l,r,f;
};
Node a[1000010];
int p[10010];
bool cmp(Node x,Node y){
    return x.f<y.f;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,cnt=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].l>>a[i].r>>a[i].f;
        p[a[i].l]++;
        p[a[i].r]++;
    }
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int i=1;i<=n;i++){
            int z;
            cin>>z;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n-1;i++){
        cnt+=a[i].f;
    }
    cout<<cnt;
    return 0;
}
