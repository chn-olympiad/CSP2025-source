#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],ans=0,ans2=0,f[500005];
void counter(){
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if(a[i]==k)
            ++f[i];
    }
}
int finder(int i){
    for(;i<=n;i++){
        if(s[i]==k)
            return i;
    }
    return -1;
}
void jhelp(int m){
    s[m+1]^=s[m];
    for(int i=m+2;i<=n;i++)
        s[i]=a[i]^s[i-1];
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    bool t=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)
            t=1;
        s[i]=a[i]^s[i-1];
    }
    if(t==0){
        cout<<n/2;
        return 0;
    }
    counter();
    int m=0;
    for(;;){
        m=finder(m+1);
        if(m!=-1){
            ++ans2;
            jhelp(m);
            ans=ans2+f[n]-f[m];
        }
        else
            break;
    }
    cout<<ans;
    return 0;
}