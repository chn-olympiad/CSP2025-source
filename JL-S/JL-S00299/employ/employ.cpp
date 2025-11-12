#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int jc(int a){
    ll ans=1;
    for(int i=1;i<=a;i++){
        ans*=i;
    }
    return ans;

}
int axy(int x,int y){
    ll m=jc(x),n=jc(x-y);
    ll t=m/n;
    return t;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int m,n;
    ll ans=0;
    string c;
    int a[510];
    cin>>m>>n;
    cin>>c;
    for(int i=0;i<m;i++) cin>>a[i];
    for(int i=n;i<=m;i++){
        ans+=axy(m,i);
    }
    ans%=998;
    ans%=244;
    ans%=353;
    cout<<ans;
    return 0;
}
