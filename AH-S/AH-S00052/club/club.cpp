#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
struct node{
    int x,y,z,idx,idy,idz;
}a[N];
int n,T,ans,cnt[4];
node swa(int u,int v,int w){
    pair<int,int>b[4];
    b[1].first=u;b[1].second=1;
    b[2].first=v;b[2].second=2;
    b[3].first=w;b[3].second=3;
    sort(b+1,b+4,greater<pair<int,int>>());
    return {b[1].first,b[2].first,b[3].first,b[1].second,b[2].second,b[3].second};
}
bool cmp(node u,node v){
    if(u.x-u.y!=v.x-v.y)return u.x-u.y>v.x-v.y;
    return u.y-u.z>v.y-v.z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        memset(a,0,sizeof a);
        ans=0;
        for(int i=1,u,v,w;i<=n;i++){
            cin>>u>>v>>w;
            a[i]=swa(u,v,w);
        }
        sort(a+1,a+n+1,cmp);
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++){
            if(cnt[a[i].idx]<n/2){
                cnt[a[i].idx]++;
                ans+=a[i].x;
            }else if(cnt[a[i].idy]<n/2){
                cnt[a[i].idy]++;
                ans+=a[i].y;
            }else{
                cnt[a[i].idz]++;
                ans+=a[i].z;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
