#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int maxa=-1,maxb=-1,maxc=-1;
void solve50(){
    const int N=205;
    int dp[N][N][N];
    memset(dp,0,sizeof(dp));
    dp[1][0][0]=a[1];
    dp[0][1][0]=b[1];
    dp[0][0][1]=c[1];
}
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i]>>b[i]>>c[i];
                maxa=max(maxa,a[i]);
                maxb=max(maxb,b[i]);
                maxc=max(maxc,c[i]);
            }
        }
        if(maxb==0&&maxc==0){
                int cop[N]
            for(int i=1;i<=n;i++){
                cop[i]=a[i];
            }
            sort(cop+1,com+n+1,cmp);
            int p=n/2,ans=0;
            for(int i=1;i<=p;i++){
                ans+=cop[i];
            }
            cout<<ans<<endl;
            continue;
        }
        if(n<=200) solve200();
    }
    return 0;
}
