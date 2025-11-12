#include<bits/stdc++.h>
using namespace std;
const int d=998244353;
int n;
int a[5010];
int jc(int x){
    long long ans=1;
    for (long long i=1;i<=x;i++){
        ans=ans*i%d;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","r",stdout);
    cin>>n;
    int cnt=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]==1)
            cnt++;
    }
    long long ans=0;
    if (n==3){
        int maxn=0,sum=0;
        for (int i=1;i<=n;i++){
            sum+=a[i];
            maxn=max(maxn,a[i]);
        }
        if (sum>maxn*2)
            cout<<1;
        else
            cout<<0;
    }
    else if (cnt==n){
            long long ans=0;
        for (int i=3;i<=n;i++){
                int num=jc(n)/(jc(i)*jc(n-i)%d)%d;
            ans=(ans+num)%d;
        }
        cout<<ans;
    }
    return 0;
}
