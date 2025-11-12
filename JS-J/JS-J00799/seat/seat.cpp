#include <bits/stdc++.h>
using namespace std;
int n,m,iop,y,x,fx;
int a[225];
int ans[15][15];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    iop=a[1];
    sort(a+1,a+n*m+1,cmp);
    x=1,y=1;
    fx=1;
    /*
    1:xia
    2:shang
    3:shangyou
    4:xiayou
    */
    for(int i=1;i<=n*m;i++){
        //cout<<fx<<endl;
        //ans[x][y]=a[i];
        if(a[i]==iop){
            cout<<y<<" "<<x<<endl;
            return 0;
        }
        //cout<<fx<<" ";
        if(fx==1){
            x++;
            if(x+1>n){
                fx=4;
            }
        }else if(fx==4){
            y++;
            fx=2;
        }else if(fx==2){
            x--;
            if(x-1<1){
                fx=3;
            }
        }else if(fx==3){
            y++;
            fx=1;
        }
    }
    return 0;
}
