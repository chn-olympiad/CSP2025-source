#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=1e5+5;

int a[N][3],n;
int del[N];

void solve(){
    int cnt[3]={0,0,0};
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        int mx=max(max(a[i][0],a[i][1]),a[i][2]);
        if(mx==a[i][0])cnt[0]++;
        else if(mx==a[i][1])cnt[1]++;
        else cnt[2]++;
        ans+=mx;
    }
    int len=0;
    int id=-1;
    for(int i=0;i<3;i++){
        if(cnt[i]>n/2)id=i;
    }
    if(id==-1){
        cout<<ans<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        int mx=max(max(a[i][0],a[i][1]),a[i][2]);
        if(mx==a[i][id]){
            del[++len]=2e9;
            for(int j=0;j<3;j++){
                if(j!=id){
                    del[len]=min(del[len],a[i][id]-a[i][j]);
                }
            }
        }
    }
    sort(del+1,del+1+len);
    for(int i=1;i<=cnt[id]-n/2;i++){
        ans-=del[i];
    }
    cout<<ans<<'\n';
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}