#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105]={};
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cnt=a[1];
    sort(a+1,a+n*m+1);
    int id=0;
    for(int i=1;i<=n*m;i++){
        if(cnt==a[i]){
            id=n*m-i+1;
            break;
        }
    }
    int r=id%n;
    if(r==0){
        int b=id/n;
        if(b%2==0) cout<<b<<" "<<1<<endl;
        else cout<<b<<" "<<n<<endl;
    }
    else{
        int b=id/n+1;
        if(b%2==0) cout<<b<<" "<<n-r+1<<endl;
        else cout<<b<<" "<<r<<endl;
    }
    return 0;
}
