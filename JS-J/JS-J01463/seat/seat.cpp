#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
    int num;// xue hao
    int sco;//cheng ji
}a[110];
bool cmp(stu a,stu b){
    if(a.sco<b.sco){
        return false;
    }
}
int res[15][15];
void place(int x,int y,int now){
    if(x>n||y>m){
       // cout<<"aaa~";
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
               // cout<<res[i][j]<<' ';
            if(res[i][j]==1){
                cout<<j<<' '<<i<<endl;
                exit(0);
            }
        }
    }

    }
    res[x][y]=a[now].num;//cout<<x<<' '<<y<<' '<<res[x][y]<<'\n';
    if(res[x+1][y]==0&&x+1<=n){
        place(x+1,y,now+1);
    }
    else if(res[x-1][y]==0&&x-1>0){
        place(x-1,y,now+1);
    }
    else {
        place(x,y+1,now+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x;
    int len=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x;
            a[++len].sco=x;
            a[len].num=len;
        }
    }
    sort(a+1,a+len+1,cmp);

    place(1,1,1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                cout<<res[i][j]<<' ';
            if(res[i][j]==1){
                cout<<i<<' '<<j<<endl;
                return 0;
            }
        }
    }
    return 0;
}
