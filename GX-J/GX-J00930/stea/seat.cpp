#include <bits/stdc++.h>

using namespace std;
int n,m,a[10000],b,c,d;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+m*n+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==b){
            c=i;
            break;
        }
    }
    d=c/n;
    if(d==0){
        if(m%2==0){
            cout<<m<<' '<<c;
        }
        else if(m%2!=0){
            cout<<m<<' '<<n-c+1;
        }
    }
    else{
        if(c%n==0){
            cout<<m-c/n+1;
            if((m-c/n+1)%2==0){
                cout<<' '<<n;
            }
            else{
                cout<<' '<<1;
            }
        }
        else if((m-c/n)%2==0){
            cout<<m-c/n<<' '<<c%n;
        }
        else if((m-c/n)%2!=0){
            cout<<m-c/n<<' '<<n-c%n+1;
        }
    }
    return 0;
}
