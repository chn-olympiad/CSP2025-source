#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2*1e5+10;
int a[N][4];
int cnt[4];
int t,n;
struct node{
    int id,w;
    bool operator < (const node &other)const{
        return w<other.w;
    }
};
int fun(int id1,int id2,int id3){
    vector<bool> vis(n,false);
    int ans=0;

}
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int ans=0;
void dfs(int id,int sum){
    if(id==n+1){
        ans=max(ans,sum);
    }
    for(int i=1;i<=3;i++){
        if(cnt[i]!=n/2){
            cnt[i]++;
            dfs(id+1,sum+a[id][i]);
            cnt[i]--;
        }
    }
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    t=read();
    while(t--){
        n=read();
        //vector<node> g[4];
        for(int i=1;i<=n;i++){
            a[i][1]=read();
            a[i][2]=read();
            a[i][3]=read();
            //cout<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<endl;

        }
        ans=0;
        memset(cnt,0,sizeof cnt);
        dfs(1,0);
        cout<<ans<<endl;
    }
}
