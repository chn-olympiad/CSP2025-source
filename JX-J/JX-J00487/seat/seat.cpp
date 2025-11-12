#include<bits/stdc++.h>
using namespace std;
long long a[150];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    int s;
    sort(a+1,a+m*n+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            s=i;
        }
    }
    if(s%(2*n)>n){
        cout<<2*n-s%(2*n)<<" "<<(s/n)+1;
    }else if(s%(2*n)==n){
        cout<<n<<" "<<s/n;
    }else{
        cout<<s%n<<" "<<s/n+1;
    }
    return 0;
}
