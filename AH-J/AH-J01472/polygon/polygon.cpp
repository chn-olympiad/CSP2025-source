#include<bits/stdc++.h>
using namespace std;
int a[5005],ans[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans[1]=a[1];
    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+a[i];
    }
    long long cnt=0;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            int maxn=0;
            for(int k=j;k<=j+i;k++){
                maxn=max(maxn,a[k]);
            }
            if((ans[j+i]-ans[j])>(2*maxn)){
                cnt++;
                cnt%=998244353;
            }
        }
    }
    cout<<cnt;
    return 0;
}
