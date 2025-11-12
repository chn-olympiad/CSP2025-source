#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m>>r;
    int a[110]={0},x=1,y=1;
    a[r]++;
    for(int i=2;i<=n*m;i++){
        int q;
        cin>>q;
        a[q]++;
    }
    for(int i=100;i>=1;i--){
        if(i==r){
            cout<<y<<" "<<x;
            return 0;
        }
        if(a[i]!=0){
            if(y%2==1){
                if(x>=n) y++;
                else x++;
            }
            else if(y%2==0){
                if(x<=1) y++;
                else x--;
            }
        }
    }
    return 0;
}
