#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int c[N],a[N],b[N];
int vis[N];
int ce[N/2];
bool cmp(int x,int y){
    return x<y;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        int ans=0;
        int ca=0,cb=0,cc=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=b[i]&&a[i]>=c[i]){
                ca++;
                vis[i]=1;
                ans+=a[i];
            }else if(b[i]>=a[i]&&b[i]>=c[i]){
                cb++;
                vis[i]=2;
                ans+=b[i];
            }else{
                cc++;
                vis[i]=3;
                ans+=c[i];
            }
        }
        if(ca>n/2){
            for(int i=1,j=1;i<=n;i++){
                if(vis[i]==1){
                    int ce1=a[i]-b[i];
                    int ce2=a[i]-c[i];
                    ce[j]=min(ce1,ce2);
                    j++;
                }
            }
            sort(ce+1,ce+ca+1,cmp);
            for(int i=1;ca>n/2;ca--,i++){
                ans-=ce[i];
            }
        }
        if(cb>n/2){
            for(int i=1,j=1;i<=n;i++){
                if(vis[i]==2){
                    int ce1=b[i]-a[i];
                    int ce2=b[i]-c[i];
                    ce[j]=min(ce1,ce2);
                    j++;
                }
            }
            sort(ce+1,ce+cb+1,cmp);
            for(int i=1;cb>n/2;cb--,i++){
                ans-=ce[i];
            }
        }
        if(cc>n/2){
            for(int i=1,j=1;i<=n;i++){
                if(vis[i]==3){
                    int ce1=c[i]-b[i];
                    int ce2=c[i]-a[i];
                    ce[j]=min(ce1,ce2);
                    j++;
                }
            }
            sort(ce,ce+cc,cmp);
            for(int i=0;cc>n/2;cc--,i++){
                ans-=ce[i];
            }
        }
        cout<<ans<<'\n';
    }
    fclose(stdout);
    return 0;
}
