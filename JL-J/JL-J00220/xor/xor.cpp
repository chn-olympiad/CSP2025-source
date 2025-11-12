#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,k;
long long a[N];
long long ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long sum=0;
        long long cnt=0;
        for(int j=i;j<=n;j++){
            sum=sum^a[j];
            if(sum==k){
                cnt++;
                sum=0;
            }
        }
        ans=max(cnt,ans);
    }
    cout<<ans<<endl;



    return 0;
}

