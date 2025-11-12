#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int M[11][11];
int cur;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)
            cur=a[i];
    }
    sort(a+1,a+1+n*m);
    reverse(a+1,a+1+n*m);
    int x=1,y=1,cnt=1;
    int d=0;
    while(1){
        M[x][y]=a[cnt++];
        if(M[x][y]==cur){
            cout<<y<<" "<<x<<'\n';
            break;
        }
        if((x%n==0&&d==0)||(x==1&&d==2)){
            y++;
            d=1;
        }else{
            if(x%n==0&&d==1){
                x--;
                d=2;
            }else{
                if(x==1&&d==1){
                    x++;
                    d=0;
                }else{
                    if(d==0)
                        x++;
                    if(d==2)
                        x--;
                }
            }
        }
    }
    return 0;
}
