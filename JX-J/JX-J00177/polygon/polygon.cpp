#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int a[5005];

int solve(int l,int r){
    int sum=1;
    for(int i=l;i<=r;i++) sum*=i;
    return sum;
}

int pg(int n,int m){
    return (solve(n+1,m)/(n+1))%N;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=2;i<=n;i++){
        sum=(sum+pg(i,n))%N;
    }
    cout<<sum;
    return 0;
}


