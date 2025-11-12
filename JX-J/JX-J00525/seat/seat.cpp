#include<bits/stdc++.h>
using namespace std;
int n,m,a[180],sum=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            sum++;
        }
    }
    if(sum%n==0){
        cout<<sum/n<<" ";
        if(sum/n%2==0){
            cout<<1;
        }
        else cout<<n;
    }
    else{
        cout<<sum/n+1<<" ";
        if(sum/n%2==0){
            cout<<sum%n;
        }
        else{
            cout<<n-sum%n+1;
        }
    }

    return 0;
}
