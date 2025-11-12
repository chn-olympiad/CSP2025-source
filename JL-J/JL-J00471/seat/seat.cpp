#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    int b[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int fs=b[1];
    sort(b+1,b+n*m+1,cmp);
    int x=1,y=1;
    int i=1,f=0;
    int d=0;
    while(true){
        a[x][y]=b[i];
        i++;
        if(a[x][y]==fs){
            cout<<x<<" "<<y;
            return 0;
        }
        if(d==0){
            if(y+1<=n)
                y++;
            else{
                d=1;
                if(x+1<=m){
                    x++;
                    f++;
                    if(f%2==1) d=2;
                    else d=0;
                }
            }
        }else if(d==2){
            if(y-1>=1)
                y--;
            else{
                d=1;
                if(x+1<=m){
                    x++;
                    f++;
                    if(f%2==1) d=2;
                    else d=0;
                }
            }
        }
    }
    return 0;
}
