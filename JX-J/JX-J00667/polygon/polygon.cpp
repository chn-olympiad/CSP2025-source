#include<bits/stdc++.h>
using namespace std;
int a[5500]={};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long c=n;
    for(int i=n-1;i>0;i--){
        for(int j=n;j>0;j--){
            c*=i;
            c/=j;
            c%=998244353;
        }
    }
    cout<<c;
    return 0;
}
