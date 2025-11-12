#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000010],cnt=1,b[110][110],f,c=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int d=n;
    f=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]!=f){
            cnt++;
        }
        else{
            break;
        }
    }
    for(int i=1;i<=n;i++,c++){
        b[i][1]=c;
    }
    for(int i=n;i>=1;i--,d++){
        b[i][2]=d+1;
    }
    for(int i=1,e=2*n;i<=n;i++,e++){
        b[i][3]=e+1;
    }
    for(int i=n,e=3*n;i>=1;i--,e++){
        b[i][4]=e+1;
    }
    for(int i=1,e=4*n;i<=n;i++,e++){
        b[i][5]=e+1;
    }
    for(int i=n,e=5*n;i>=1;i--,e++){
        b[i][6]=e+1;
    }
    for(int i=1,e=6*n;i<=n;i++,e++){
        b[i][7]=e+1;
    }
    for(int i=n,e=7*n;i>=1;i--,e++){
        b[i][8]=e+1;
    }
    for(int i=1,e=8*n;i<=n;i++,e++){
        b[i][9]=e+1;
    }
    for(int i=n,e=9*n;i>=1;i--,e++){
        b[i][10]=e+1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cnt==b[i][j]){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}
