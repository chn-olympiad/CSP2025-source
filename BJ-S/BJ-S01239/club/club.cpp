#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100005][5],bm[100005],cntbm[5],b[100005];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        memset(cntbm,0,sizeof(cntbm));
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
                bm[i]=1;
                ans+=a[i][1];
                cntbm[1]++;
            }
            else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
                bm[i]=2;
                ans+=a[i][2];
                cntbm[2]++;
            }
            else if(a[i][3]>=a[i][2] && a[i][3]>=a[i][1]){
                bm[i]=3;
                ans+=a[i][3];
                cntbm[3]++;
            }
        }
        if(cntbm[1]>n/2){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(bm[i]==1){
                    b[++cnt]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
                }
            }
            sort(b+1,b+cnt+1,greater<int>());
            for(int i=1;i<=cnt-n/2;i++){
                ans+=b[i];
            }
        }
        else if(cntbm[2]>n/2){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(bm[i]==2){
                    b[++cnt]=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
                }
            }
            sort(b+1,b+cnt+1,greater<int>());
            for(int i=1;i<=cnt-n/2;i++){
                ans+=b[i];
            }
        }
        else if(cntbm[3]>n/2){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(bm[i]==3){
                    b[++cnt]=max(a[i][2]-a[i][3],a[i][1]-a[i][3]);
                }
            }
            sort(b+1,b+cnt+1,greater<int>());
            for(int i=1;i<=cnt-n/2;i++){
                ans+=b[i];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
