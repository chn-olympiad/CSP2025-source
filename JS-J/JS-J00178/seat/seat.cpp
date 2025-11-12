#include<bits/stdc++.h>
using namespace std;
int a[107],n,m;
int num=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            num++;
        }
    }
    //cout<<num<<" ";
    int mod=num%n;
    int line=num/n;
    if(mod){line++;}
    else{cout<<line<<" "<<n;return 0;}
    if(line%2){cout<<line<<" "<<mod;}
    else{cout<<line<<" "<<n-mod+1;}
    return 0;
}
