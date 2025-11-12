#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
struct stu{
    int x,y,z;

}a[M],b[10][N];
int f[N];
bool st[10];
bool cmp(stu xx,stu yy){
    return xx.z<yy.z;
}
long long ans;
int n,m,k;
int find(int x){
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
      ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    for(int i=1;i<=n;i++)f[i]=i;
    sort(a+1,a+n+1,cmp);
    while(k--){
        int x;
        for(int i=0;i<=n;i++)cin>>x;

    }
    for(int i=1;i<=n;i++){
        int x=a[i].x,y=a[i].y,z=a[i].z;
        x=find(x),y=find(y);
        if(x!=y){
            ans+=z;
            f[x]=y;
        }
    }
    cout<<ans;
    return 0;
}

