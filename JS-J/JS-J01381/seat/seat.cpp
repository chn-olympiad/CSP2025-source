#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int b[15][15],x,y,t;
int flag;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    x=1;
    y=1;
    flag=1;
    for(int i=1;i<=n*m;++i){
        if(x+1<=n&&flag==1){
            b[x][y]=a[i];
            x++;
        }else if(x==n&&flag==1){
            b[x][y]=a[i];
            y++;
            flag=2;
        }else if(x>1&&flag==2){
            b[x][y]=a[i];
            x--;
        }else if(x==1&&flag==2){
            b[x][y]=a[i];
            y++;
            flag=1;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(t==b[i][j]){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
