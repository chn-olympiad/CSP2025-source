#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,li1[5005],ans;
void fuc(){
    bool flag[5005];
    for(int i=0;i<5005;i++){
        flag[i]=false;
    }
    for(int i=3;i<n;i++){
        for(int j=0;j<i;j++){
            flag[j]=true;
        }
    }
}
int C(int x,int y){
    long long re=1;
    for(int i=max(y,x-y)+1;i<=x;i++){
        re=re*i%mod;
    }
    for(int i=2;i<=min(y,x-y);i++){
        re=re/i%mod;
    }
    return re;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>li1[i];
    }
    sort(li1,li1+n);
    fuc();
    for(int i=3;i<=n;i++){
        ans=ans+C(n,i)%mod;
    }
    cout<<ans;
    return 0;
}
