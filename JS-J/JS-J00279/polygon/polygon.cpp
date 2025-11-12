#include<bits/stdc++.h>
using namespace std;
const int maxn=5050;
const long long mod=998244353;
long long a[maxn],sum=0;
bool b[maxn];
int n;
void df(int d){
    if(d==n+1){
        long long cnt=0,ans=0,maxa=0;
        for(int i=1;i<=n;i++){
            if(b[i]){
                ans+=a[i];
                cnt++;
                maxa=max(maxa,a[i]);
            }
        }
        if(cnt>=3&&ans>2*maxa)sum=(sum+1)%mod;
    }else{
        b[d]=1;
        df(d+1);
        b[d]=0;
        df(d+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    df(0);
    cout<<sum/2<<endl;
    return 0;
}
