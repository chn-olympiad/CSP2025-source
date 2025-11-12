#include<bits/stdc++.h>
using namespace std;
int n,m,p[105],cnt=0,r,g,x=1,y=1,k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt++;
            cin>>p[cnt];
        }
    }
    r=p[1];
    sort(p+1,p+1+cnt);
    for(int i=1;i<=cnt;i++){
        if(p[i]==r){
            g=cnt-i+1;
            break;
        }
    }
    k=1;
    for(int i=1;i<=g-1;i++){
        if(x+1>n&&k==1){
            k=2;
            y++;
        }
        else if(x-1<1&&k==2){
            k=1;
            y++;
        }
        else{
           if(k==1){
                x++;
            }
            else if(k==2){
                x--;
            }
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
