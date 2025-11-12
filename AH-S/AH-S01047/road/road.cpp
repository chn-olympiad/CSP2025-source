#include<bits/stdc++.h>
using namespace std;
long long n,m,k,maxx,ans;
long long u[1000005],v[1000005],w[1000005];
long long c[15],a[10005][10005],father[1000005];
long long find_father(long long x){
    if(father[x]==x)return x;
    else return find_father(father[x]);
}
void union_father(long long ax,long long by){
    long long fx=find_father(ax);
    long long fy=find_father(by);
    father[fx]=fy;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]>10000){
            int yu;
            for(int j=1;j<=n;j++){
                cin>>yu;
            }
        }
        for(int j=1;j<=n;j++){
            cin>>a[c[i]][j];
            maxx=max(maxx,a[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=m;j>=2;j--){
            if(w[i]<w[i-1]){
                swap(u[i],u[i-1]);
                swap(v[i],v[i-1]);
                swap(w[i],w[i-1]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(find_father(u[i])!=find_father(v[i])){
            union_father(u[i],v[i]);
            if(a[u[i]][v[i]]==0)ans+=w[i];
            else ans+=min(a[u[i]][v[i]],w[i]);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
