#include<stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 150005
#define int long
struct peo{
    int a,b,c;
    int cse,mvl;
}val[MAXN+5];
int w,n,ans;
vector<peo> vec[5];
inline int read(){
    int x=0;
    char c=getchar();
    while(c>'9'||c<'0'){
        c=getchar();
    }
    while(c<='9'&&c>='0'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
signed main(){
    //freopen("/home/csps/ans/T1/club/club3.in","r",stdin);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    w=read();
    while(w--){
        ans=0;
        n=read();
        for(int i=1;i<=n;i++){
            val[i].a=read(),val[i].b=read(),val[i].c=read();
            //cin>>val[i].a>>val[i].b>>val[i].c;
            int mx=max({val[i].a,val[i].b,val[i].c});
            if(val[i].a==mx) val[i].cse=1,val[i].mvl=mx-max(val[i].b,val[i].c);
            else if(val[i].b==mx) val[i].cse=2,val[i].mvl=mx-max(val[i].a,val[i].c);
            else if(val[i].c==mx) val[i].cse=3,val[i].mvl=mx-max(val[i].a,val[i].b);
            ans+=mx;
        }
        for(int i=1;i<=n;i++){
            vec[val[i].cse].push_back(val[i]);
        }
        for(int i=1;i<=3;i++){
            sort(vec[i].begin(),vec[i].end(),[](const peo& a,const peo& b)mutable->bool{
               return a.mvl>b.mvl;
            });
            if(vec[i].size()>n/2){
                int t=vec[i].size()-1;
                while(t>=n/2){
                    ans-=vec[i][t].mvl;
                    t--;
                }
                break;
            }
        }
        printf("%ld\n",ans);
        //cout<<ans<<endl;
        vec[1].clear();
        vec[2].clear();
        vec[3].clear();
    }
    return 0;
}
