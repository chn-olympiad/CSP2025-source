#include <bits/stdc++.h>
using namespace std;
constexpr int N=10005,M=1000005,K=15;
int n,m,k;
long long ans=LONG_LONG_MAX;
bool noa=true;
pair<int,pair<int,int>> eg[M],eg2[M+N*K],ca[K][N];
int c[K],cb[K];
int fa[N+K],sz[N+K];
void init(int ta=n+1){
    for (int z=0;z<=ta;z++){
        fa[z]=z;
        sz[z]=1;
    }
}
int fin(int p){
    int q=p,tmp;
    while (fa[q]!=q)q=fa[q];
    while (fa[p]!=p){tmp=p;p=fa[p];fa[tmp]=q;}
    return q;
}
void uni(int a,int b){
    int p=fin(a),q=fin(b);
    if (sz[p]>sz[q]){
        fa[q]=p;
        sz[p]+=sz[q];
    }else{
        fa[p]=q;
        sz[q]+=sz[p];
    }
}
bool isu(int a,int b){
    return fin(a)==fin(b);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    init();
    for (int z=0;z<m;z++){
        cin>>eg[z].second.first>>eg[z].second.second>>eg[z].first;
    }
    if (k==0){
        sort(eg,eg+m);
        for (int z=0;z<m;z++){
            if (!isu(eg[z].second.first,eg[z].second.second)){
                ans+=eg[z].first;
                uni(eg[z].second.first,eg[z].second.second);
            }
        }
        cout<<ans;
        return 0;
    }
    for (int z=0;z<k;z++){
        bool tmp=0;
        cin>>c[z];
        for (int y=1;y<=n;y++){
            cin>>ca[z][y].first;
            ca[z][y].second.first=n+z+1;
            ca[z][y].second.second=y;
            if (ca[z][y].first==0){tmp=1;cb[z]=y;}
        }
        noa&=(!c[z] && tmp);
    }
    if (noa){
        init(n+k+1);
        memcpy(eg2,eg,sizeof(eg[0])*m);
        int ptr=m;
        for (int p=0;p<k;p++){
            memcpy(eg2+ptr,ca[p],sizeof(ca[p]));
            ptr+=n;
        }
        sort(eg2,eg2+ptr);
        ans=0;
        for (int z=0;z<ptr;z++){
            if (!isu(eg2[z].second.first,eg2[z].second.second)){
//                cout<<eg2[z].second.first<<' '<<eg2[z].second.second<<' '<<eg2[z].first<<'@';
                ans+=eg2[z].first;
                uni(eg2[z].second.first,eg2[z].second.second);
            }
        }
        cout<<ans;
        return 0;
    }
    for (int z=0,ptr=0;z<(1<<k);z++){
        long long tmp=0;
        init(n+k+1);
        memcpy(eg2,eg,sizeof(eg[0])*m);
        ptr=m;
        for (int p=0;p<k;p++){
            if (z&(1<<p)){
                tmp+=c[p];
                memcpy(eg2+ptr,ca[p],sizeof(ca[p]));
                ptr+=n;
            }
        }
        sort(eg2,eg2+ptr);
        for (int z=0;z<ptr;z++){
            if (!isu(eg2[z].second.first,eg2[z].second.second)){
                tmp+=eg2[z].first;
                uni(eg2[z].second.first,eg2[z].second.second);
            }
        }
        ans=min(ans,tmp);
    }
    cout<<ans;
    return 0;
}
