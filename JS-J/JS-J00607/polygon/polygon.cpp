#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+5e2,MOD=998244353;
ll f[N],n,sum=0;
vector<bool>v(N+1,0);
//int dp[N];//dp[i]is i sticks' max ways
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>f[i];
    }sort(f+1,f+n+1,greater<ll>());
    while(!v[n+1]){
        if(v[1]==0){
            v[1]=1;
        }else{
            bool jw=1;
            for(ll i=1;i<=n+100;i++){
                if(v[i]==1&&jw){
                    v[i]=0;
                }else{
                    if(v[i]==0&&jw){
                        v[i]=1;
                        jw=0;
                    }
                }
            }
        }bool flag=0;
            ll maxn=0,cnt=0;
            for(ll i=1;i<=n;i++){
                if(v[i]&&!flag){
                    maxn=f[i];
                    flag=1;
                }if(v[i]){
                    cnt+=f[i];
                }
            }if(maxn*2<cnt){
                sum++;
                sum%=MOD;
                /*for(int i=1;i<=n;i++){
                    if(v[i]){
                        cout<<f[i]<<" ";
                    }
                }cout<<endl;*/
            }
    }cout<<sum;
    /*dp[0]=d[1]=dp[2]=0;
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-1]+)
    }*/
    /*sort(f+1,f+n+1,greater<int>());
    int cnt=0;
    for(int i=2;i<=n;i++){
        cnt+=f[i];
    }if(cnt<=f[i]){
        cout<<0;
        return 0;
    }*/
    return 0;
}
