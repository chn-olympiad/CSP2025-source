#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+5],s[n+5],sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1) s[i]=s[i-1]^a[i];
        else s[i]=a[i];
    }
    for(int i=n;i>=1;i--){
        if(s[i]==k) sum++;
    }
    for(int i=2;i<=n;i++){
        if(a[i]==k) sum++;
    }
    cout<<sum<<endl;
    return 0;
}
