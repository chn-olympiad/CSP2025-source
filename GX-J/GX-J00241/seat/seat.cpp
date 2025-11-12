#include<bits/stdc++.h>
using namespace std;
long long n,m,a,xx,b,x,y,yy;
long long syx[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<=(n*m)-1;i++){
        cin>>a;
        syx[a]++;
        if(i==0){
            xx=a;
        }
    }
    for(long long i=101;i>=0;i--){
        while(syx[i]!=0){
            b++;
            if(i==xx){
               x=b;
            }
            syx[i]--;
        }
    }
    y=0;
    yy=0;
    if(x%n==0){
        y=x/n;
    }
    else{
        y=x/n;
        y++;
    }
    if(x%n==0){
        yy=m;
    }
    else{
        yy=x%n;
    }

    if(n%2!=0){
        cout<<y<<" "<<yy;
    }
    else{
        cout<<y<<" "<<m-(yy-1);
    }

    return 0;
}
