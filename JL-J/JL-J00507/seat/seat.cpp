#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    if(n==1&&m==1){
        cout<<n<<" "<<m;
        return 0;
    }
    else{
        if(n%2==0){
            cout<<n<<" 1";
            return 0;
        }
        else{
            cout<<n<<" "<<m;
            return 0;
        }
    }
    return 0;
}
