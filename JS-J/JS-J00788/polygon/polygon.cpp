#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans,b[5050],i;
bool pand(){
    sort(b,b+i-1);
    int summ=0;
    for(int j=0;j<i+1;j++){
        summ+=b[j];
    }
    if (2*b[i-1] < summ) return true;
    else return false;
}
void d(int k,int be){
    if (k==i){
        if (pand()) ans++;
        return;
    }
    k++;
    for(int j=be+1;j<=n;j++){
        b[k] = a[j];
        d(k,j);
    }
    k--;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=3;i<=n;i++){
        d(-1,-1);
    }
    cout<<(ans) % 998244353 ;
    return 0;
}
