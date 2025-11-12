#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,fa[100020],k,c[10020];
int a[20][10020];
int findfa(int f){
    if(fa[f]==f){
        return f;
    }
    return fa[f]=findfa(fa[f]);
}
struct node{
    int x,y,l;
    bool operator <(const node &W)const{
        return l<W.l;
    }
};
node mp[5000010];
int idx;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x,y,l;
        cin>>x>>y>>l;
        mp[++idx]={x,y,l};
    }
    int t=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0){
            t=1;
        }
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(!k){
        sort(mp+1,mp+m+1);
        int ans=0;
        for(int i=1;i<=m;i++){
            int fl=findfa(mp[i].x),fr=findfa(mp[i].y);
            if(fl!=fr){
                ans+=mp[i].l;
                fa[fl]=fr;
            }
        }
        cout<<ans;
    }else if(!t){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                mp[++idx]={j,n+i,a[i][j]};
            }
        }
        sort(mp+1,mp+idx+1);
        int ans=0;
        for(int i=1;i<=idx;i++){
            if(mp[i].x>n||mp[i].y>n){
                continue;
            }
            int fl=findfa(mp[i].x),fr=findfa(mp[i].y);
            if(fl!=fr){
                ans+=mp[i].l;
                fa[fl]=fr;
            }
        }
        cout<<ans;
    }
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 9 9 9 9
*/
