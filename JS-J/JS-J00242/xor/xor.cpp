#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    long long a[n+2],b[n+2],cnt=0,c[22];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
    int cnt,sum;
        for(int i=n-1;i>=1;i++){
            sum+=i;
            cnt++;
        }
        cout<<n*cnt-sum<<endl;
    }
    else
        cout<<n-2<,endl;
    return 0;
}
