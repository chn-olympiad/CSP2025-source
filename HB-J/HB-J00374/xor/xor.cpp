#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000],g[500001],ans=0,u;
bool f[256];
pair<int,int> part[500000];
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first==y.first){
        return x.second<y.second;
    }
    return x.first<y.first;
}
int abs(int x){
    return x>=0?x:-x;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==0){
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==0){
                ans++;
            }
            cout<<ans;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        g[i+1]=(g[i]+a[i])%k;
    }
    int m=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(g[i]-g[j]==0){
                part[m].first=i;
                part[m].second=j;
                m++;
            }
        }
    }
    sort(part,part+m,cmp);
    u=0;
    for(int i=0;i<m;i++){
        if(part[i].first>=u){
            u=part[i].second;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
