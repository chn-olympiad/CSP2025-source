#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long ans;
const long long k=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<(1<<n);i++){
        long long sum=0;
        int num=0;
        int maxx=-1;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                num++;
                sum+=a[j];
                maxx=max(maxx,a[j]);
            }
        }
        if(num>=3&&sum>maxx*2){
            ans++;
        }
    }
    cout<<ans%k;
    return 0;
}
