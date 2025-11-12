#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int n,sum[5001],a[5001],ans;
bool check(int i){
    int maxx=-1,sum=0,cnt=1,num=0;
    while(i){
        if(i%2){
            maxx=max(maxx,a[cnt]);
            sum+=a[cnt];
            num++;
        }
        i/=2;
        cnt++;
    }
    if(num<3){
        return 0;
    }
    else{
        return (sum>(maxx*2));
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n>20){
        cout<<n-2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=((1<<n)-1);i++)
    {
        ans+=check(i);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}