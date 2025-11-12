//18:15 12
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define fi first
#define se second
using ll=long long;
const int N=505,mod=998244353;
int n,m,c[N],p[N],tmp;
ll ans;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;s=" "+s;
    for(int i=1;i<=n;i++)   cin>>c[i];
    for(int i=1;i<=n;i++)   tmp+=(s[i]=='1');
    if(n<=10){
        for(int i=1;i<=n;i++)   p[i]=i;
        int cnt=0;
        do{
            cnt=0;
            for(int i=1;i<=n;i++){
                if(s[i]=='0'||cnt>=c[p[i]]) cnt++;
            }
            ans+=(n-cnt>=m);
        }while(next_permutation(p+1,p+n+1));
        cout<<ans%mod<<"\n";
    }else if(m==n){
        ans=1;bool ff=0;
        for(int i=1;i<=n;i++)   ans=ans*i%mod;
        for(int i=1;i<=n;i++)   ff|=(c[i]==0);
        if(tmp!=n||ff)  ans=0;
        cout<<ans<<"\n";
    }else if(m==1){

    }else if(tmp<=18){
        for(int i=0;i<(1<<tmp);i++);
    }
}