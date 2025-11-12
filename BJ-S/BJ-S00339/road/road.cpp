#include<bits/stdc++.h>

using namespace std;
 int mod=998244353;
int main(){
    freopen("employ3.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[510],b[510],t[510];
    int s=0;
    for(int i=0;i<n;i++){
    char z;
    cin>>z;
        a[i]=z-'0';
        if(a[i]==0){
            s++;
        }
        t[i]=s;
    }
    int ans=1;
    int f=n;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]==0){
            f--;
        }
    }
    for(int i=0;i<f;i++){
        ans=(((long long)ans%mod)*(f-i))%mod;
    }

    cout<<ans;
    return 0;
}
