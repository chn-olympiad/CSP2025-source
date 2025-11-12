#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=5e3+10,M=998244353;
int n,s,mx,a[N],b[N];
ull ans;
ull qp(ull a,ull b){
    ull s=1;
    while(b){
        if(b&1){
            s*=a;
            s%=M;
        }
        a*=a;
        a%=M;
        b>>=1;
    }
    return s;
}
bool check(){
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        for(int i=0;i<(1<<n);i++){
            if(__builtin_popcount(i)>=3){
                s=mx=0;
                for(int j=n-1;j>=0;j--){
                    if((1<<j)&i){
                        s+=a[j+1];
                        mx=max(mx,a[j+1]);
                    }
                }
                if(s>(mx<<1)){
                    ans++;
                }
            }
        }
        cout<<ans;
    }
    else if(check()){
        ans=qp(2,n);
        ans--;//C(n,0)
        ans-=n;//C(n,1)
        ans-=(n*(n-1)>>1);//C(n,2)
        cout<<ans;
    }
    else{
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            b[i]=b[i-1]+a[i];
        }
        for(int i=3;i<=n;i++){//a[i]=max
            for(int j=1;j<=i;j++){
                int t=upper_bound(b+1,b+1+i,(a[i]<<1)+b[j-1])-b;//the first >
                //b[t]-b[j-1]>(a[i]<<1)
                //b[t]>(a[i]<<1)+b[j-1]
                if(t==i+1){
                    break;
                }
                ans+=qp(2,i-t)-1;
                if(ans>=M){
                    ans%=M;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
