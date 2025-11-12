#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
const int N=1e5+5;
int T,n,sum[4][N],len[4],st[4],ans,a,b,c;
struct node{
    int p[4];
}s[N];
bool cmp(int x,int y) {
    return s[x].p[a]-max(s[x].p[b],s[x].p[c])>s[y].p[a]-max(s[y].p[b],s[y].p[c]);
}
void solve(int id){
    if(id==1) a=1,b=2,c=3;
    else if(id==2) a=2,b=1,c=3;
    else a=3,b=1,c=2;
//    cout<<x<<' '<<y<<' '<<z<<' ';
    sort(sum[a]+1,sum[a]+1+len[a],cmp);
    per(i,len[a],n/2+1){
        node u=s[sum[a][i]];
        if(u.p[b]>u.p[c]) sum[b][++len[b]]=sum[a][i];
        else sum[c][++len[c]]=sum[a][i];
        --len[a];
    }
}
void work(){
    ans=0;
    memset(len,0,sizeof len);
    cin>>n;
    rep(i,1,n) {
        cin>>s[i].p[1]>>s[i].p[2]>>s[i].p[3];
        int c=max(s[i].p[1],max(s[i].p[2],s[i].p[3]));
        rep(j,1,3) if(s[i].p[j]==c) {sum[j][++len[j]]=i; break;}
    }
    rep(i,1,3) if(len[i]>n/2) solve(i);
    rep(i,1,3) rep(j,1,len[i]) ans+=s[sum[i][j]].p[i];
    cout<<ans<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--) work();
    return 0;
}
