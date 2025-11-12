#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn],f[maxn];
int fun(int a,int b){
    int ans=0,p=1;
    while(a||b){
        ans+=(((!(a%2))&(b%2))||((a%2)&(!(b%2))))*p;
        p*=2;a/=2;b/=2;
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;long long k;
    cin>>n;cin>>k;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];f[i]=a[i];
        if(f[i]==k){
            ans++;
            f[i]=LLONG_MAX;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=n;j>=i;j--){
            if(f[j-1]==LLONG_MAX){
                f[j]=LLONG_MAX;
                continue;
            }
            else if(f[j]==LLONG_MAX)continue;
            else{
                f[j]=fun(f[j],f[j-1]);
                if(f[j]==k){
                    ans++;
                    f[j]=LLONG_MAX;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
