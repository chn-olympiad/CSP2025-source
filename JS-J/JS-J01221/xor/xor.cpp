#include<bits/stdc++.h>
using namespace std;
long long n,k,a[600000],m,ma;
void f(long long x){
    if(x>=n+1){
        ma=max(ma,m);
        return ;
    }
    long long b;
    for(int i=x;i<=n;i++){
        b=0;
        for(int j=i;j<=n;j++){
            b^=a[j];
            if(b==k){
                m++;
                f(j+1);
                m--;
                break;
            }
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    f(1);
    cout<<ma;
    return 0;
}
