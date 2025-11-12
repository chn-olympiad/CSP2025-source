#include<bits/stdc++.h>
using namespace std;
long long a[110],b[50][50],n,m,x=0,y=1,cnt=0,bj=0,jg=0,t;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cin>>a[i*j];
    }
    t=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(cnt<n&&bj==0){
            x++;
            jg++;
            cnt++;
            b[x][y]=a[i];
        }
        else if(cnt<n){
            x--;
            jg++;
            cnt++;
            b[x][y]=a[i];
        }
        else if(cnt==n){
            cnt=1;
            if(bj==1){
                bj=0;
            }
            else{
                bj=1;
            }
            y++;
            jg++;
            b[x][y]=a[i];
        }

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==t){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}


