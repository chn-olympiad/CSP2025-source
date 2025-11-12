#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,a[20],ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long i=3;
    while(i<=n){
        long long w=0,q=0;
        for(int x=i;x>=1;x--){
            w+=a[x];
            q=max(q,a[x]);
        }
        cout<<w<<" "<<q<<endl;
        if(w>q){
            ans++;
        }
        i++;
    }
    cout<<ans%998244353;
    return 0;
}
