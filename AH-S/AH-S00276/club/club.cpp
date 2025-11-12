#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,b[10];
struct kx{
    int maxn1,id1,maxn2,id2,del;
}f[N];
bool cmp(kx g,kx h){
    return g.del>h.del;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(b,0,sizeof(b));
        memset(f,0,sizeof(f));
        cin>>n;
        for(int i=1;i<=n;i++) f[i].maxn1=f[i].maxn2=f[i].id1=f[i].id2=f[i].del=0;
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(a>=b&&b>=c){
                f[i].maxn1=a,f[i].id1=1;
                f[i].maxn2=b,f[i].id2=2;
            }
            else if(a>=c&&c>=b){
                f[i].maxn1=a,f[i].id1=1;
                f[i].maxn2=c,f[i].id2=3;
            }
            else if(b>=a&&a>=c){
                f[i].maxn1=b,f[i].id1=2;
                f[i].maxn2=a,f[i].id2=1;
            }else if(b>=c&&c>=a){
                f[i].maxn1=b,f[i].id1=2;
                f[i].maxn2=c,f[i].id2=3;
            }else if(c>=a&&a>=b){
                f[i].maxn1=c,f[i].id1=3;
                f[i].maxn2=a,f[i].id2=a;
            }else if(c>=b&&b>=a){
                f[i].maxn1=c,f[i].id1=3;
                f[i].maxn2=b,f[i].id2=2;
            }
            f[i].del=f[i].maxn1-f[i].maxn2;
        }
        sort(f+1,f+1+n,cmp);
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(b[f[i].id1]<n/2) {
                ans+=f[i].maxn1;
                b[f[i].id1]++;
            }else{
                ans+=f[i].maxn2;
                b[f[i].id2]++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
