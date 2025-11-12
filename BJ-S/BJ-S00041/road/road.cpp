#include<bits/stdc++.h>
using namespace std;

long long n,m,k,cnt,f[2001000];
struct node{
    long long l,r,x;
}a[2001000];
bool cmp(node a,node b){
    return a.x<b.x;
}
int fd(int x){
    if(f[x]!=x){
        f[x]=fd(f[x]);
        return f[x];
    }else{
        return x;
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin >> a[i].l >> a[i].r >> a[i].x;
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=n;i++){
        if(fd(a[i].l)==fd(a[i].r)){
            continue;
        }
        cnt+=a[i].x;
        f[f[a[i].l]]=f[a[i].r];
     //   cout << f[a[i].l] << ' ' << a[i].r << endl;
    }
    cout << cnt << endl;
























































































    return 0;
}
