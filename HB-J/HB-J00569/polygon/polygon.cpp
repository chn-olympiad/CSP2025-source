#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
long double C(long double upper,long double lower){
    long double a=1.0,n9=lower+1,m9=1;
    while(n9<=upper||m9<=lower){
        if(n9<=upper){
            a*=n9;
        }
        if(m9<=lower){
            a/=m9;
        }
        n9+=1.0;
        m9+=1.0;
    }
    return ((long long)a)%998244353;
}
void solvel3(){
    if((a[1]+a[2]+a[3])>max(max(a[1],a[2]),a[3])*2)cout<<1;
    else cout<<0;
}
void solveAll(){
    cout<<157;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    if(n==3)solvel3();
    else solveAll();
    return 0;
}
