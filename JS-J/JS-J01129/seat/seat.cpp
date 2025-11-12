#include<bits/stdc++.h>
using namespace std;
int a[105];
int mp[12][12];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int num=n*m;
    for(int i=1;i<=num;i++) cin>>a[i];
    int xiaor=a[1];
    sort(a+1,a+num+1);
    int x=1,y=1;
    bool flg=1;
    while(flg){
        while(x<=n&&flg){
            if(num){
                mp[x][y]=a[num];
                x++;
                num--;
            }else{
                flg=0;
                break;
            }
        }if(x>n){x--;num++;}
        if(y+1<=m&&flg){
            if(num){
                mp[x][y]=a[num];
                y++;
                num--;
            }else{
                flg=0;
                break;
            }
        }
        while(x>=1&&flg){
            if(num){
                mp[x][y]=a[num];
                x--;
                num--;
            }else{
                flg=0;
                break;
            }
        }if(x<1){x++;num++;}
        if(y+1<=m&&flg){
            if(num){
                mp[x][y]=a[num];
                y++;
                num--;
            }else{
                flg=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==xiaor){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
