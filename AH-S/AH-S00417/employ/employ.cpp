#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int mod=998244353;
bool check(string s){
    for(int i=0;i<s.size();++i)if(!s[i])return false;
    return true;
}
ll A(int m,int n){
        ll ans=1;
        for(int i=n;i>=n-m+1;--i)ans=(ans*i)%mod;
        return ans;
    }
string s;
int n,m,c[N];
namespace task0{//all questions are easy
    void solve(){
        cout<<A(n,n)<<endl;
    }
}
namespace task1{
    void solve(){
        cout<<A(n,n)<<endl;
    }
}
namespace task3{
    
    void solve(){
        if(!check(s))cout<<0<<endl;
        else cout<<A(n,n)<<endl;
    }
}
namespace task05{
    int cnt=0;
    void solve(){
        for(int i=1;i<=n;++i){
            if(c[i]==0)c[i]=0x3f3f3f;
            ++cnt;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;++i){
        cin>>c[i];
    }
    if(check(s))task0::solve();
    else if(m==1)task1::solve();
    else if(m==n)task3::solve();
    else{
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(c[i]==0)c[i]=0x3f3f3f;
            ++cnt;
    }
    cout<<A(cnt,cnt)*A(n-cnt,n-cnt)%mod<<endl;
    return 0;


}