#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;

    int a[n*m+5];
    int xm=0;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    if(n<=1 and m<=1){
        cout<<1<<" "<<1<<" ";
        return 0;
    }
    xm=a[1];
    int y=0;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==xm){
            y=n*m-i+1;
        }
    }
    int u=1;
    int l=m*n;
    while(l!=0){
        if(l-n+1<=y<=l){
            cout<<u<<" ";
            break;
        }
        u++;
        l=l-n;
    }





   int d=1;


    int t=m*n;

    if(y%n==0){
        cout<<m<<" ";
        return 0;
    }
    else{
        if(y<n){
            cout<<y%n<<" ";
            return 0;
        }
        if(d*n<y<=(d+1)*n){
            cout<<y-d*n<<" ";
            return 0;
        }
        d++;
    }

    return 0;
}
