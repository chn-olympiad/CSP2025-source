#include<bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define ull unsigned long long
//#define int long long
using namespace std;
const int N=1e4+11,mod=998244353;
int n,m;
int c[N];
void solve(){

}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    string s;
    cin>>s;
    bool f=1;
    for(int i=0;i<s.size();++i){
        if(s[i]!='1'){
            f=0;
        }
    }
    rep(i,1,n){
        scanf("%d",c+i);
    }
    if(f==1){
        int a[N];
        for(int i=1;i<=n;++i){
            a[i]=i;
        }
        int cnt=0;
        do{
            cnt=(cnt+1)%mod;
        }while(next_permutation(a+1,a+n+1));
        printf("%d",cnt%mod);
    }
    return 0;
}

