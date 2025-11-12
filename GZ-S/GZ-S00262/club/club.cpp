//GZ-S00262,贵州,杨帆乐,520113200802190033,贵阳市南明甲秀高级中学,高三
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
//#include <uility>
#define MAXN 100005
#define ll long long

using namespace std;

int t,n;

struct val{
    ll w;
    int pos,ii;

    bool operator > (const val &b)const{
        return w>b.w;
    }
};

vector<val> vec;
bool vis[MAXN];
int cnt[3];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ll a=0,b=0,c=0;
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
            vec.push_back({a,1,i});
            vec.push_back({b,2,i});
            vec.push_back({c,3,i});
        }
        sort(vec.begin(),vec.end(),greater<val>());
        for(val k:vec){
            //cout<<k.w<<" "<<k.pos<<" "<<k.ii<<endl;
            //cout<<(vis[k.ii]||cnt[k.pos]>=n/2)<<endl<<endl;
            if(vis[k.ii]||cnt[k.pos]>=n/2)continue;
            ans+=k.w;
            //cout<<cnt[2]<<endl;
            //cout<<k.w<<" "<<k.pos<<" "<<k.ii<<endl;
            vis[k.ii]=true;
            cnt[k.pos]++;
        }
        cout<<ans<<endl;
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        vec.clear();
    }
}

