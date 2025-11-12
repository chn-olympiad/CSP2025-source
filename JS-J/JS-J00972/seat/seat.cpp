#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n,m;
int x=1,y=1;
int p;
int ii=1;
int xx;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    p=a[1];
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++){
        if(a[i]==p){
            xx=n*m-i+1;
            break;
        }
    }
    for(int i=1;i<=xx-1;i++){
        if(n==1){
            y++;
        }
       else if(x==1 && y%2==1){
            x++;
       }else if(x==1 && y%2==0){
          // cout<<"tytytytytye\n";
           y++;
       }else if(x==n && y%2==1){
           y++;
       }else if(x==n && y%2==0){
           x--;
       }else if(y%2==1){
           x++;
       }else if(y%2==0){
           x--;
       }
       //cout<<x<<" ";
    }
    cout<<y<<" "<<x;
    return 0;
}
