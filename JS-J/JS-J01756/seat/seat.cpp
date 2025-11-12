#include<bits/stdc++.h>
using namespace std;
const int N=105;
int dlt[2][2]{
    {1,0},
    {-1,0},
};
int a[N];
int k;
int cnt;
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    cnt=n*m;
    sort(a+1,a+n*m+1);
    int f=0;
    int x=0,y=1;
    while(1){
        int tx=x+dlt[f][0];
        int ty=y+dlt[f][1];
        if(tx>0&&tx<=n&&ty>0&&ty<=n){
            if(a[cnt]==k){
                cout<<ty<<' '<<tx<<endl;
                break;
            }else{
                x=tx;
                y=ty;
                cnt--;
            }
        }else{
            if(tx>n){
                tx--;
                ty++;
                if(a[cnt]==k){
                    cout<<ty<<' '<<tx<<endl;
                    break;
                }else{
                    cnt--;
                    x=tx;
                    y=ty;
                    f=(f+1)%2;
                }
            }else if(tx<1){
                tx++;
                ty++;
                if(a[cnt]==k){
                    cout<<ty<<' '<<tx<<endl;
                    break;
                }else{
                    cnt--;
                    x=tx;
                    y=ty;
                    f=(f+1)%2;
                }
            }
        }
    }
    return 0;
}