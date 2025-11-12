#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[101],b[11][11],a1[101],l,r,sum;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++){
        cin>>a[i];
        if(i == 1) s = a[i];
    }
    sort(a+1,a+n*m+1);
    for(int i = 1;i<=n*m;i++){
        if(a[i] == s) sum = n*m-i+1;
    }
    if(sum % n == 0){
        l = sum / n;
        r = n;
    }
    else{
        l = sum / n + 1;
        r = sum % n;
    }
    cout<<l<<" ";
    if(l %2 == 0){
        cout<<n-r+1;
    }
    else{
        cout<<r;
    }
}
