#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[5050],ans=0;
const long long Mod=998244353;
void dfs(long long d,long long last,long long sum,long long maxn){
    if(d>=3){
        if(sum>maxn*2){
            ans++;
        }
    }
    for(long long i=last+1; i<=n; i++){
        dfs(d+1,i,sum+a[i],max(maxn,a[i]));
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n<=20){//   10/25
        dfs(0,0,0,0);
        cout<<ans;
        return 0;
    }
    long long maxn=0,cnt=0;//   6/25
    for(long long i=1; i<=n; i++){
        maxn=(maxn,a[i]);
        if(a[i]==1){
            cnt++;
        }
    }
    if(maxn==1){
        if(cnt<3){
            cout<<0;
            return 0;
        }
        if(cnt>=3){
            if(cnt==3){
                cout<<1;
                return 0;
            }
            long long ans=cnt+1;
            for(long long i=cnt; i>=5; i--){
                ans+=cnt*(cnt-1)/2;
                ans%=Mod;
            }
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
