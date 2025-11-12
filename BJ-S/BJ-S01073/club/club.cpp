#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN=100005;
#define int long long
int t,n;
struct peo{
    int x,o1,o2;
    int idx;
    peo(int x,int idx,int o1,int o2):
        x(x),idx(idx),o1(max(o1,o2)),o2(min(o1,o2))
    {}
    peo(){}
    bool operator < (const peo &rhs) const {
        if(x!=rhs.x)
            return x>rhs.x;
        if(o1!=rhs.o1)
            return o1<rhs.o1;
        return o2<rhs.o2;
    }
};
struct opeo{
    int x1,x2,x3;
    opeo(){}
    opeo(int x1,int x2,int x3):
        x1(x1),x2(x2),x3(x3)
    {}
};
vector<peo> c1,c2,c3;
peo ab[5];
bitset<MAXN> used;
int ans;
opeo pe[MAXN];
void dfs(int t1,int t2,int t3,int now,int tot){
    if(now==n+1){
        ans=max(ans,tot);
        return;
    }
    if(t1<n/2)
        dfs(t1+1,t2,t3,now+1,tot+pe[now].x1);
    if(t2<n/2)
        dfs(t1,t2+1,t3,now+1,tot+pe[now].x2);
    if(t3<n/2)
        dfs(t1,t2,t3+1,now+1,tot+pe[now].x3);
    return;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    // cout<<"out\n";
    while(t--){
        cin>>n;
        // cout<<"out\n";
        if(n<=30){
            ans=0;
            for(int i=1;i<=n;++i){
                int x,y,z;
                cin>>x>>y>>z;
                pe[i]=opeo(x,y,z);
            }
            dfs(0,0,0,1,0);
            cout<<ans<<'\n';
        }else{
            used.reset();
            c1.clear();
            c2.clear();
            c3.clear();
            ans=0;
            bool f=0;
            for(int i=1;i<=n;++i){
                int x,y,z;
                cin>>x>>y>>z;
                if(y!=0||z!=0)
                    f=1;
                c1.emplace_back(peo(x,i,y,z));
                c2.emplace_back(peo(y,i,x,z));
                c3.emplace_back(peo(z,i,x,y));
            }
            sort(c1.begin(),c1.end());
            sort(c2.begin(),c2.end());
            sort(c3.begin(),c3.end());
            // for(auto i:c1){
            //     cout<<i.x<<" "<<i.idx<<'\n';
            // }
            // cout<<'\n';
            // for(auto i:c2){
            //     cout<<i.x<<" "<<i.idx<<'\n';
            // }
            // cout<<'\n';
            // for(auto i:c3){
            //     cout<<i.x<<" "<<i.idx<<'\n';
            // }
            if(!f){
                for(int i=0;i<n/2;++i)
                    ans+=c1[i].x;
                cout<<ans<<'\n';
                continue;
            }
            int l[4]={0,0,0,0};
            int cnt=0;
            int act[4]={0,0,0,0};
            while(cnt<n){
                
                while(l[1]<n&&used[c1[l[1]].idx])
                    ++l[1];
                while(l[2]<n&&used[c2[l[2]].idx])
                    ++l[2];
                while(l[3]<n&&used[c3[l[3]].idx])
                    ++l[3];
                // cout<<l[1]<<" "<<l[2]<<" "<<l[3]<<'\n';
                // cout<<ans<<'\n';
                ab[1]=c1[l[1]];
                ab[2]=c2[l[2]];
                ab[3]=c3[l[3]];
                int maxn=-1,midx,lidx;
                for(int j=1;j<=3;++j){
                    if(ab[j].x>maxn&&act[j]<n/2){
                        maxn=ab[j].x;
                        lidx=j;
                        midx=ab[j].idx;
                    }
                }
                ++cnt;
                ans+=maxn;
                used[midx]=1;
                l[lidx]++;
                act[lidx]++;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}