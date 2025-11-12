#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
inline int read(){
    int f=1,res=0;
    char ch=getchar_unlocked();
    while(ch<'0' || ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0' && ch<='9'){
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar_unlocked();
    }
    return f*res;
}
int t,n,cnt[4],ans,a[N][4],b[N],res;
int used[N];
void dfs(int x){
    if(x==n+1){
        ans=max(ans,res);
        return;
    }
    for(register int i=1;i<=3;i++){
        if(cnt[i]>=n/2)continue;
        used[x]=i;
        cnt[i]++;
        res+=a[x][i];
        dfs(x+1);
        cnt[i]--;
        res-=a[x][i];
    }
}
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    bool flg;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        flg=1;
        ans=res=0;
        for(register int i=1;i<=n;i++){
            for(register int j=1;j<=3;j++){
                cin>>a[i][j];
                if(j==1)b[i]=a[i][j];
                if(j>1 && a[i][j]!=0)flg=0;
            }
        }
        if(flg){
            sort(b+1,b+n+1,cmp);
            for(register int i=1;i<=n/2;i++){ans+=b[i];}
            cout<<ans<<'\n';
            continue;
        }
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
