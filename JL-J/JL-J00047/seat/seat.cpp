#include<bits/stdc++.h>
using namespace std;
int n,m;
int x=1,y=1;
int a[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int w=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(i==1&&j==1){
                w=a[i][j];
            }
            else{
                if(a[i][j]>w){
                    if(x%2==1){
                        if(y+1>m){
                            x++;
                        }
                        else{
                            y++;
                        }
                    }
                    else{
                        if(y-1<1){
                            x++;
                        }
                        else{
                            y--;
                        }
                    }
                }
            }
        }
    }
    cout<<x<<' '<<y<<'\n';
}

//今年T2好简单
