#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
int n,m;
int a[25][25];
int s[205];
int sx;
void dfs(int x,int y,int now,bool l){
    if(now>n*m){
        cout<<-1;
        exit(0);
    }
    a[x][y]=s[now];
    if(s[now]==sx){
        cout<<x<<' '<<y;
        exit(0);
    }
    now++;
    if(l){
        if(y==m) x++,l=0;
        else y++;
    }
    else{
        if(y==1) x++,l=1;
        else y--;
    }
    dfs(x,y,now,l);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fin("seat.in");fout("seat.out");
    cin>>n>>m;
    rep(i,1,n*m) cin>>s[i];
    sx=s[1];
    sort(s+1,s+n*m+1,greater<int>() );
    dfs(1,1,1,1);


    return 0;
}
//running limit time 3e8
