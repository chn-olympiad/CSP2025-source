#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define mkp make_pair
#define fi first
#define se second
const int N=400024,mod=998244353;
int n,m,ans,p[N],c[N];
string s;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        p[i]=i;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            if(c[i]==0){
                cout<<0;
                return 0;
            }
        }
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    if(n<=10){
        do{
            int gvp=0;
            for(int i=1;i<=n;i++){
                if(gvp>=c[p[i]]||s[i-1]=='0'){
                    gvp++;
                }
            }
            if(n-gvp>=m) ans++;
        }while(next_permutation(p+1,p+1+n));
        cout<<ans<<"\n";
    }
    else{
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
}