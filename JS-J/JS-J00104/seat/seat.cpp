#include <bits/stdc++.h>
using namespace std;
int c=0,r=0,n,m;
int s[12][12];
struct node{
    int num;
    int score;
}a[102];
bool cmp(node a,node b){
    return a.score>b.score;
}
void dfs(int x,int y,int k,bool flag){
    s[x][y]=a[k].num;
    if(x==n&&y==m) return ;
    int nx=x,ny=y;
    bool nflag=flag;
    if(flag==false) nx++;
    else nx--;
    if(nx>n){
        nx=n;
        ny++;
        nflag=!nflag;
    }else if(nx<1){
        nx=1;
        ny++;
        nflag=!nflag;
    }
    dfs(nx,ny,k+1,nflag);
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].score;
        a[i].num=i;
    }
    sort(a+1,a+n*m+1,cmp);
    dfs(1,1,1,false);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==1){
                r=i;
                c=j;
                break;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
