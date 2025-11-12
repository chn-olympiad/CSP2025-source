#include <bits/stdc++.h>

using namespace std;
struct pm{
    long long x;
    long long y;
    long long w;
    long long j1;
};
long long n,m,k,a[20005],c[20005],d[25],l=1,l1,ans=1000000000000000,e[25],f[20005];
pm b[2000005];
bool cmp(pm n1,pm m1){
    return n1.w<m1.w;
}
int cha(int n1){
    if(f[n1]==n1){
        return n1;
    }
    return f[n1]=cha(f[n1]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    d[0]=1;
    for(int i=1;i<=k;i++){
        l=l*2;
    }
    l1=m+1;
    for(int i=1;i<=m;i++){
        cin>>b[i].x>>b[i].y>>b[i].w;
    }
     for(int i=1;i<=k;i++){
        cin>>e[i];
        for(int j=1;j<=n;j++){
            cin>>b[l1].w;
            b[l1].x=n+i;
            b[l1].y=j;
            b[l1].j1=i;
            l1++;
        }
    }
    sort(b+1,b+l1,cmp);
    for(int i=0;i<l;i++){
        long long i1=i,ans1=0;
        for(int j=1;j<=k;j++){
            d[j]=i1%2;
            if(d[j]==1){
                ans1=ans1+e[j];
            }
            i1=i1/2;
        }
        for(int j=1;j<=n+k;j++){
            f[j]=j;
        }
        for(int j=1;j<l1;j++){
            if(d[b[j].j1]==0){
                continue;
            }
            int f1,f2;
            f1=cha(b[j].x);
            f2=cha(b[j].y);
            if(f1==f2){
                continue;
            }
            if(f2<f1){
                swap(f2,f1);
            }
            f[f2]=f1;
            ans1=ans1+b[j].w;
        }
        if(ans1<ans){
            ans=ans1;
        }
    }
    cout<<ans;

    return 0;
}
