#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define TII array<int,3>
const int maxn=1e5+5;
int T,n,ans,cnta,cntb,cntc,a[maxn],b[maxn],c[maxn];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n,ans=0;
        cnta=cntb=cntc=0;
        for(int i=1,x,y,z;i<=n;i++){
            cin>>x>>y>>z;
            if(x>=y and x>=z){
                ans+=x,a[++cnta]=max(y,z)-x;
            }else{
                if(y>=x and y>=z){
                    ans+=y,b[++cntb]=max(x,z)-y;
                }else{
                    ans+=z,c[++cntc]=max(x,y)-z;
                }
            }
        }
        if(cnta>(n>>1)){
            sort(a+1,a+1+cnta);
            while(cnta>(n>>1))ans+=a[cnta],cnta--;
        }else{
            if(cntb>(n>>1)){
                sort(b+1,b+1+cntb);
                while(cntb>(n>>1))ans+=b[cntb],cntb--;
            }else{
                sort(c+1,c+1+cntc);
                while(cntc>(n>>1))ans+=c[cntc],cntc--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}