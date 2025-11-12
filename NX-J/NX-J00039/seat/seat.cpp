#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1];
    for(int i=1;i<n*m;i++){
            int b;
        if(a[i]<a[i+1]){
            b=a[i];
            a[i]=a[i+1];
            a[i+1]=b;
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            x=i;
            break;
        }
    }
    if(x/n==0){
        cout<<1<<" ";
    }
    else{
        cout<<x/n<<" ";
    }
    if(x%n==0){
        cout<<n;
    }
    else{
        cout<<x%n;
    }
    return 0;
}
