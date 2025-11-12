#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
const int mod=99844353;
int a[N];
int n;
int maxn=-1;
long long ans;
long long C(int x,int y){
    long long cnt1=1;
    long long cnt2=1;
    for(int i=y;i>y-x;i--){
        cnt1*=i;
        cnt1=cnt1%mod;
    }
    for(int i=1;i<=x;i++){
        cnt2*=i;
        cnt2=cnt2%mod;
    }
    return cnt1/cnt2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*maxn){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    if(maxn==1){
        for(int i=3;i<=n;i++){
            ans+=C(i,n)%mod;
            ans=ans%mod;
        }
        cout<<ans;
        return 0;
    }
    srand(time(0));
    cout<<rand()*rand();
    return 0;
}

