#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P=998244353;
int fp(int a,int b){
    if(b==0)return 1;
    if(b==1)return a;
    int f=fp(a,b/2);
    if(b&1)return f*f%P*a%P;
    else return f*f%P;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    if(s.find("0")==-1){
        int ans=1;
        for(int i=m+1;i<=n;i++)ans=ans*i%P;
        for(int i=1;i<=n-m;i++)ans=ans*fp(i,P-2)%P;
        cout<<ans;
    }else cout<<0;
    return 0;
}