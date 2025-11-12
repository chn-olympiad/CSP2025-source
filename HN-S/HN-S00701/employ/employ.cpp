// 太好了我能在城市配送比赛中获得 59pts 的好成绩！
#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
long long fact[1919810];
constexpr long long mod=998244353ll;
int main(){
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i%mod;
    }
    if(n<=10){
        cin>>s;
        s=' '+s;
        for(int i=1;i<=n;i++)cin>>c[i];
        vector<int> mask(n);
        for(int i=0;i<n;i++)mask[i]=i;
        int ans=0;
        do{
        	int giveup=0;
            for(int i=0;i<n;i++){
                if(s[i]=='0'||giveup>=c[mask[i]]){
                	giveup++;
                }
            }
            if((n-giveup)>=m) ans++;
        }while(next_permutation(mask.begin(),mask.end()));
        cout<<ans;
    }else{
        long long ans=1ll;
        for(int i=n;i>m;i--){
            ans=ans*i%mod;
        }
        cout<<ans;
    }
}
