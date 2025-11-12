#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+5;
using ll=long long;
int n,lim,a[N][4];
void solveBC(){
    ll ans=0;
    for(int i=2;i<=n;i+=2){
        int all=max(a[i][1]+a[i-1][2],a[i][2]+a[i-1][1]);
        ans+=all;
    }
    cout<<ans<<'\n';
}
struct point{
    int a1,a2,a3;
    int id;
}b[N];
int num[4];
int pos,posone,tt;
ll ans;
int v[N],p[N][4];
bool cmp(point x,point y){
    int dx=x.a1-x.a2;
    int dy=y.a1-y.a2;
    return dx<dy;
}
bool cmp2(point x,point y){
    int l1=p[x.id][3],l2=p[y.id][3];
    if(p[x.id][2]==p[y.id][2]){
        if(l1==posone)return false;
        if(l2==posone)return true;
        return x.a2-x.a3<y.a2-y.a3;
    }
    else return p[x.id][2]==pos;
}
void solve_move(){
    for(int i=1;i<=n;i++){
        b[i].a1=a[i][p[i][1]],b[i].a2=a[i][p[i][2]];
        b[i].a3=a[i][p[i][3]],b[i].id=i;
    }
    sort(b+1,b+n+1,cmp2);
    for(int i=1;i<=num[pos]-lim;i++){
        if(p[b[i].id][3]==posone)continu
        ans-=(b[i].a2-b[i].a3);
    }
}
void solve_text(){
    for(int i=1;i<=n;i++){
        int all=max(a[i][1],max(a[i][2],a[i][3]));
        for(int j=1;j<=3;j++)
            if(a[i][j]==all)
                p[i][1]==j;
        ans+=all;
        all=min(a[i][1],min(a[i][2],a[i][3]));
        for(int j=1;j<=3;j++)
            if(a[i][j]==all and j!=p[i][1])
                p[i][3]==j;
        p[i][2]=6-p[i][1]-p[i][3];
        num[p[i][1]]++;
    }
    for(int j=1;j<=3;j++)
    if(num[j]>lim){
        posone=j;
        for(int i=1;i<=n;i++){
            if(p[i][1]==pos){
                tt++;
                b[tt].a1=a[i][p[i][1]],b[tt].a2=a[i][p[i][2]];
                b[tt].a3=a[i][p[i][3]],b[tt].id=i;
            }
        }
        sort(b+1,b+tt+1,cmp);
        for(int i=1;i<=num[j]-lim;i++)ans-=(b[i].a1-b[i].a2),
            num[p[b[i].id][2]]++;
        num[j]=lim;
        for(int l=1;l<=3;l++){
            if(num[l]>lim){
                    pos=l;
                solve_move();
                break;
            }
        }
        break;
    }
    cout<<ans<<'\n';
}
void init(){
    ans=0,pos=0,tt=0;
    memset(num,0,sizeof num);
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
void solve(){
    init();
    cin>>n;
    lim=n/2;
    for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
    bool f=true;
    for(int i=1;i<=n;i++)if(a[i][3]!=0)f=false;
    if(f)solveBC();
    else solve_text();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)solve();
}
