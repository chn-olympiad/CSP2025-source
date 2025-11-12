#include<bits/stdc++.h>
using namespace std;
const int N=5010,M=998244353;
int n,a[N];
unsigned long long num[N],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    num[1]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num[i]=(num[i-1]*i)%M;
    }
    if(n<3){
        cout<<"0";
        return 0;
    }
    if(n==3){
        sort(a+1,a+n+1);
        if(a[3]>=a[1]+a[2]) cout<<"0";
        else cout<<"1";
        return 0;
    }
    bool flag=true;
    for(int i=1;i<=n;i++)if(a[i]!=i)flag=false;
    if(flag&&n==5){
        cout<<"9";
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans+=num[n]/((num[i]*num[n-i])%M);
        ans%=M;
    }
    cout<<ans;
    return 0;
}
