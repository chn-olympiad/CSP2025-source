#include<bits/stdc++.h>
using namespace std;
int n,m,h[20][20],a[110],a1,k,g,x,y;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    a1=a[1];
    sort(a+1,a+n*m+1);
    g=1;
    x=1;
    y=1;
    while(1){
        if(a[k]==a1){
            cout<<x<<" "<<y;
            return 0;
        }
        k--;
        if(x%2==1){
            y++;
            if(y>n){
                y--;
                x++;
            }
        }
        else{
            y--;
            if(y<1){
                y++;
                x++;
            }
        }
    }
    return 0;
}


