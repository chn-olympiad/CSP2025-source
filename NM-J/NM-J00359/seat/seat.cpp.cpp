#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+5];
    for(int i=1;i<=n*m;i++){
    cin>>a[i];
    }
    int b=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
    if(a[i]==b){
    int c=i%n;
    cout<<i/n<<" ";
    if(i%n==0) c=n;
        if((i/n+1)%2==0) cout<<n-c+1;
        else cout<<c;
        break;
    }
    }
    return 0;
}

