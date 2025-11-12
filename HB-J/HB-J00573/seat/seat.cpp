#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int i,n,m,a[101]={},f=1;
    cin>>n>>m;
    for(i=1;i<=n*m;i++)cin>>a[i];
    for(i=2;i<=n*m;i++){
        if(a[i]>a[1])f++;
    }
    if(f%n==0){
       if((f/n)%2==1)cout<<f/n<<" "<<n<<endl;
          else cout<<f/n<<" "<<1<<endl;
    }
       else {
             cout<<f/n+1<<" ";
             if((f/n+1)%2==1)cout<<f%n<<endl;
                else cout<<n+1-f%n<<endl;

    }
    return 0;
}
