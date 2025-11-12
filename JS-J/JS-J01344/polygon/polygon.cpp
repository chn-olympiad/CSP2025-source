#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const long long mod=998244353;
int n,a[N];
long long ans;
void f(int now,int num,int sum,int Max){
    if(now==n){
        if(num>=3&&sum>2*Max){
            ans++;
            ans%=mod;
            return;
        }
        else  return;
    }
    f(now+1,num+1,sum+a[now+1],max(Max,a[now+1]));
    f(now+1,num,sum,Max);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    f(0,0,0,0);
    cout<<ans<<endl;
    return 0;
}
