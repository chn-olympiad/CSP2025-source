#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long ans=0;
    vector<long long> s(n+1);
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]^a[i];
    }
    int j=1,p=1;
    while(j<=n){
        for(int j1=p;j1<=j;j1++){
            long long t;
            if(j1==1){
                t=s[j];
            }else{
                t=s[j]^s[j1-1];
            }
            if(t==k){
                p=j+1;
                ans++;
                break;
            }
        }
        j++;
    }
    cout<<ans<<'\n';
    return 0;
}
