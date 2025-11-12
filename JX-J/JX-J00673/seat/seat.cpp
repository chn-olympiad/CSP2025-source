#include<bits/stdc++.h>
using namespace std;
long long n,m;
int x;
long long a[1010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]==x){
            x=n*m-i+1;
            break;
        }
    }
    if(x%m==0){
        if(x/m%2==1){
            cout<<x/m<<" "<<m;
        }
        else{
            cout<<x/m<<" "<<1;
        }
    }
    else{
        if((x/m+1)%2==0){
            cout<<x/m+1<<" "<<m-x%m+1;
        }
        else{
            cout<<x/m+1<<" "<<x%m;
        }
    }
    return 0;
}
