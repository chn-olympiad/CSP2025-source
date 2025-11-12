#include<bits/stdc++.h>
using namespace std;
int a[5010];
const int p=998244353;
int f(int x,int y){
    long long int cnt=1;
    for(int i=y;i>y-x;i--){
        cnt*=i;
        cnt%=p;
    }
    for(int i=1;i<=x;i++){
        cnt/=i;
    }
    return cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int b=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b=max(b,a[i]);
    }
    if(b==1){
        long long ans=0;
        for(int i=3;i<=n;i++){
            ans+=f(i,n);
            ans%=p;
        }
        cout<<ans;
    }else{
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
        }
        if(sum>b*2){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
