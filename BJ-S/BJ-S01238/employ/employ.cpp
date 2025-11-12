#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define x first
#define y second
int n,m;
const int N=500,mod=998244353;
string s;
int c[N+5];
int p[N+5];
int calc(int n){
    int res=1;
    for(int i=n;i>=2;i--) res=(res*i)%mod;
    return res;
}
bool check(void){
    int cnt=0;//不成功的
    for(int i=1;i<=n;i++){
        if(cnt>=c[p[i]]) cnt++;
        else if(s[i-1]=='0') cnt++;
    }
    return n-cnt>=m;
}
void case1(void){
    int T=calc(n);
    for(int i=1;i<=n;i++) p[i]=i;
    int res=0;
    while(T--){
        next_permutation(p+1,p+n+1);
        if(check()) res++;
    }
    cout<<res;
    return ;
}
void case3(void){
    for(int i=0;i<n;i++) if(s[i]=='0'){
        cout<<0;
        return ;
    }
    cout<<calc(n);
}
void case2(void){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(c[i]==0) cnt++;
    }
    cout<<calc(n-cnt);
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    bool flag=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') flag=1;
    }
    if(n<=10) case1();
    else if(m==n) case3();
    else if(!flag) case2();
    else cout<<0;
    return 0;
}

