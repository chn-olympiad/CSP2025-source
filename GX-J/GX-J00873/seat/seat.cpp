#include<bits/stdc++.h>
using namespace std;
int a[200],n,m,a1,r,c;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    a1=a[0];
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++)//(n*m-i) is the rate of 'R
        if(a1==a[i]){
//          cout<<n*m-i<<'#';
            c=(n*m-i-1)/n+1;
            if((n*m-i-1)%(2*n)<n){//going down
                r=(n*m-i-1)%n+1;
//              cout<<"down";
            }else{//going up
                r=n-(n*m-i-1)%n;
//              cout<<"up";
            }
        }
    cout<<c<<' '<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
