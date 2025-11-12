#include<bits/stdc++.h>
using namespace std;

int n,m;
int x=0,y=1,dirc=1;
int a[105];
int seats[15][15];

bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    if(n==1&&m==1){
        cout<<n<<' '<<m;
        return 0;
    }
    if(n==1&&m!=1){
        int p=a[1];
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++){
            if(a[i]==p){
                cout<<n<<' '<<i;
                break;
            }
        }
        return 0;
    }
    if(m==1&&n!=1){
        int p=a[1];
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(a[i]==p){
                cout<<i<<' '<<m;
                break;
            }
        }
        return 0;
    }
    int cnt=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        x+=dirc;
        if(x==n+1||x==0){
            x-=dirc;
            y++;
            dirc*=-1;
            seats[x][y]=a[i];
        }
        else {
            seats[x][y]=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           if(seats[i][j]==cnt){
            cout<<j<<' '<<i;
            return 0;
           }
        }
    }
    return 0;
}
//2 2
//99 100 97 98
