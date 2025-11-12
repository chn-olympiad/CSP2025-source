#include<bits/stdc++.h>
using namespace std;
int a[2100000],n,m,k,zb;
bool cmp(int x,int y){
    return x>y;
}
int x,y=1,f=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>k;
    a[1]=k;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
    if(f==0){
        x++;
        if(x==n+1){
            f=1;
            y++;
            x=n;
        }
    }else{
        x--;
        if(x==0){
            y++;
            f=0;
            x=1;
        }
    }
        if(a[i]==k){
        cout<<y<<" "<<x<<endl;
            break;
        }
    }

return 0;
}
