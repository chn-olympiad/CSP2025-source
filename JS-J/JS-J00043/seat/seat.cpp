#include<bits/stdc++.h>
using namespace std;
int n,m,id=1;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int target;
    cin>>a[1];
    target=a[1];
    for (int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>target){
            id++;
        }
    }
    if(id%n==0){
        if(id/n%2==1){
            cout<<id/n<<" "<<n;
        }
        else if(id/n%2==0){
            cout<<id/n<<" "<<1;
        }
        return 0;
    }
    if(id/n%2==0){
        cout<<id/n+1<<" "<<id%n;
    }
    else if(id/n%2==1){
        cout<<id/n+1<<" "<<n-id%n+1;
    }
    return 0;
}
