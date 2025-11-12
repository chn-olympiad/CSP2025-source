#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,a[N][5],cnt[4];
struct node{
    int b,c;
}f[N];
bool cmp(node x,node y){
    return x.c<y.c;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n; int ans=0;
        cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;i++) f[i].c=f[i].b=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            ans+=max(a[i][1],max(a[i][2],a[i][3]));
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                f[i].b=1; f[i].c=a[i][1]-max(a[i][2],a[i][3]);
                cnt[1]++;
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
               f[i].b=2; f[i].c=a[i][2]-max(a[i][1],a[i][3]);
                cnt[2]++;
            }
            else{
                f[i].b=3; f[i].c=a[i][3]-max(a[i][1],a[i][2]);
                cnt[3]++;
            }
        }
        int x=0;
        for(int i=1;i<=3;i++){
            if(cnt[i]>n/2) x=i;
        }
        if(x==0){
            cout<<ans<<"\n";
        }
        else{
            sort(f+1,f+1+n,cmp); int k=cnt[x]-(n/2),num=0;
            for(int i=1;i<=n;i++){
                if(f[i].b==x){
                    ans-=f[i].c; ++num;
                }
                if(num>=k) break;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}