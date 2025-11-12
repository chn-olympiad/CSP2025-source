#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int f(int x,int y){
    long long ans=1;
    for(int i=x;i>=y;i--){
        ans*=i;
     //   ans%=998244353;
    }
    return ans;
}
int C(int i,int n){
    long long ans1=f(i+1,n)/(f(1,i));
    return ans1%998244353;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int maxn=-1;
    long long tot=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //if(a[i]!=1) flag=0; 
        maxn=max(a[i],maxn);
        tot+=a[i];
    }
    if(maxn==1){
        long long ans=0;
        for(int i=3;i<=n;i++){
            ans+=C(i,n);
            ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
    else if(n<=3){
        if(tot>2*maxn){
            cout<<'1';
        }else{
            cout<<'0';
        }
        return 0;
    }
    else cout<<'0';
    return 0;
}