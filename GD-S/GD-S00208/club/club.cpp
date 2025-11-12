#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int n;
int a[maxn+5][5];
int d[maxn+5];
int cnt[5];
int ans;
inline int Read(){
    char ch=getchar();
    int rs=0;
    for(;ch<'0'||'9'<ch;ch=getchar());
    for(;'0'<=ch&&ch<='9';ch=getchar())
        rs=(rs<<1)+(rs<<3)+ch-'0';
    return rs;
}
inline void Solve(){
    n=Read();
    cnt[1]=cnt[2]=cnt[3]=0;
    for(int i=1;i<=n;i++){
        a[i][0]=1;
        for(int j=1;j<=3;j++){
            a[i][j]=Read();
            if(a[i][j]>a[i][a[i][0]])
                a[i][0]=j;
        }
        cnt[a[i][0]]++;
    }
    ans=0;
    if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
        for(int i=1;i<=n;i++) ans+=a[i][a[i][0]];
    }
    else{
        cnt[0]=1;
        for(int j=1;j<=3;j++)
            if(cnt[j]>cnt[cnt[0]])
                cnt[0]=j;
        for(int i=1;i<=n;i++){
            swap(a[i][1],a[i][cnt[0]]);
            d[i]=max(a[i][2],a[i][3])-a[i][1];
            ans+=a[i][1];
        }
        sort(d+1,d+n+1);
        for(int i=n;i>n/2;i--) ans+=d[i];    
    }
    printf("%d\n",ans);
}
signed main(){
    // const double stim=clock();
    freopen("club.in","r",stdin);
    // freopen("club5.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=Read();
    while(T--) Solve();
    // cerr<<(clock()-stim)/CLOCKS_PER_SEC;
    return 0;
}