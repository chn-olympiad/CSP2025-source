#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{
    constexpr int maxn=1e5+3;int adjust[3][maxn];
    inline int Main(){
        int test;cin>>test;while(test--){
            int n;cin>>n;int count[3]={0,0,0},ans=0;for(int i=1;i<=n;++i){
                int val[3];for(int j=0;j<3;++j)cin>>val[j];
                int maxx=val[0],iter=0;for(int j=1;j<3;++j)
                    if(val[j]>maxx)maxx=val[j],iter=j;
                int second=-1;for(int j=0;j<3;++j)
                    if(j!=iter)second=max(second,val[j]);
                ans+=maxx,adjust[iter][++count[iter]]=maxx-second;
            }int iter=-1;for(int j=0;j<3;++j)if(count[j]>n>>1)iter=j;
            if(iter==-1)cout<<ans<<'\n';
            else{sort(adjust[iter]+1,adjust[iter]+count[iter]+1);
                for(int i=1;i<=count[iter]-(n>>1);++i)ans-=adjust[iter][i];
                cout<<ans<<'\n';}
        }return 0;
    }
}
int main(){freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    SOLUTION::Main();return 0;
}