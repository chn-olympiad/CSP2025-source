#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,a,y,b=0,c;
    cin>>n>>m;
    int cj[n*m];
    for(int i=1;i<=n*m;i++){
        cin>>cj[i-1];
    }
    c=cj[0];
    sort(cj+0,cj+0+n*m);
    for(int i=n*m;i>0;i--){
        if(cj[i]==c){
            a=b;
            break;
        }
        b++;
    }
    if(a<=n){
        a=a%n+a/n+1;
        cout<<1<<' '<<a;
    }
    else{
        x=a/n+1;
        if(x%2==0){
            y=a%n+1;
        }
        else{
            y=a%n;
        }
        cout<<x<<' '<<y;
    }
    return 0;
}
