#include<bits/stdc++.h>
using namespace std;
#define int long long
const int dir[4][2]={0,1,1,0,0,-1,1,0};
int n,m,a[1005],w,nx,ny,d,ch;
void fs(int x,int y,int cnt){
    if(a[cnt]==w){
        cout<<x<<' '<<y;
        return ;
    }
    if(ch==1){
        ++d;
        ch=0;
    }
    else if(d==0&&y==n||d==2&&y==1){
        ++d;
        ch=1;
    }
    if(d==4) d=0;
    fs(x+dir[d][0],y+dir[d][1],cnt-1);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
        cin>>a[i];
    w=a[1];
    sort(a+1,a+1+n*m);
    fs(1,1,n*m);
    return 0;
}
