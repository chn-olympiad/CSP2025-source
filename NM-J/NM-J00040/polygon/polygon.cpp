#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
int b(int m,long long n,long long m1=0){
    if(m==-1){
        if(m1>n)return 1;else return 0;
    }
    return b(m-1,n,m1+a[m])+b(m-1,n,m1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(n==3){
        if(a[2]>a[0]+a[1])cout<<1;
        else cout<<0;
    }
    else{
        long long z=0;
        for(int i=2;i<n;i++){
            z=(z+b(i-1,a[i],0))%998244353;
        }
        cout<<z;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
