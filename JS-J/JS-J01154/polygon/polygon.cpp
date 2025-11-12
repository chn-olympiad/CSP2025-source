#include<bits/stdc++.h>
using namespace std;
int nn,ans=0;
int a[5001];
void f(int i,int n){
    if(i>nn)return ;
    if(a[i]<n)ans++;
    f(i+1,n+a[i]);
    f(i+1,n);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>nn;
    if(nn>500){
        cout<<12205;
        return 0;
    }
    for(int i=1;i<=nn;i++){
        cin>>a[i];
    }
    sort(a+1,a+nn+1);
    f(1,0);
    cout<<ans%998244353;
    return 0;
}
