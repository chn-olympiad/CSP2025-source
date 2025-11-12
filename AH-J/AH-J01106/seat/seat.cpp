#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a[100001],b,c=1;
    cin>>n>>m;
    b=n*m;
    for(int i=0;i<b;i++){
        cin>>a[i];
    }
    for(int i=1;i<=b-1;i++){
        if(a[0]<a[i]){
            c++;
        }
    }
    int x,y;
    x=c/n;
    y=c%n;
    if(y==0){
        cout<<n<<" "<<x;
    }
    else{
        cout<<y<<" "<<x+1;
    }

}
