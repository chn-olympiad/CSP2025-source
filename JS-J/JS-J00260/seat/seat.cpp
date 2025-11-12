#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int rf;
int cj[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++){
        cin>>cj[i];
        if(i == 1){
            rf = cj[1];
        }
    }
    sort(cj+1,cj+1+n*m);
    for(int i = n*m;i>=1;i--){
        int y = 0,x = 0;
        y = ceil((n*m-i+1)*1.0/n);
        if(y%2 == 0){
            x = n-(n*m-i+1)%n+1;
        }
        else{
            x = (n*m-i+1)%n;

        }
        if(cj[i] == rf){
            cout<<y<<" "<<x;
            return 0;
        }
    }
}
