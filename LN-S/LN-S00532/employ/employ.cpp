#include<bits/stdc++.h>
using namespace std;
long long K=1e5;
int main(){
    long long n,m,a[10000],p=1,j;
    cin>>n>>m;
    string s;
    cin>>s;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    j=0;
    for(int i=n;i>=m;i--){
        p*=(n-j);
        j++;
    }
    if(m==1){
        p=2*m;
    }
    cout<<p/2;
    return 0;
}
