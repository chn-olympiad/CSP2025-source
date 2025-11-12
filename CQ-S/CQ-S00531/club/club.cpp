#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
namespace shan{
    int t,n;
    struct peo_t{
        int a[3],b[3];
    }p[N];
    vector<int>dt[3];
    signed main(){
        cin>>t;
        while(t--){
            cin>>n;
            int cnt[3]={0,0,0},ans=0;
            for(int i=1;i<=n;i++){
                cin>>p[i].a[0]>>p[i].a[1]>>p[i].a[2];
                memcpy(p[i].b,p[i].a,sizeof(p[i].a));
                sort(p[i].b,p[i].b+3);
                int me=p[i].b[2]-p[i].b[1];
                if(p[i].b[2]==p[i].a[0]){
                    cnt[0]++;
                    dt[0].push_back(me);
                }else if(p[i].b[2]==p[i].a[1]){
                    cnt[1]++;
                    dt[1].push_back(me);
                }else{
                    cnt[2]++;
                    dt[2].push_back(me);
                }
                ans+=p[i].b[2];
            }
            sort(dt[0].begin(),dt[0].end());
            sort(dt[1].begin(),dt[1].end());
            sort(dt[2].begin(),dt[2].end());
            int hf=n/2;
            if(cnt[0]>hf){
                for(int i=0;i<cnt[0]-hf;i++)
                    ans-=dt[0][i];
            }else if(cnt[1]>hf){
                for(int i=0;i<cnt[1]-hf;i++)
                    ans-=dt[1][i];
            }else if(cnt[2]>hf){
                for(int i=0;i<cnt[2]-hf;i++)
                    ans-=dt[2][i];
            }
            cout<<ans<<'\n';
            dt[0].clear();
            dt[1].clear();
            dt[2].clear();
        }
        return 0;
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    shan::main();
    return 0;
}
/*
hard to code
*800 ?
*/