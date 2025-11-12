#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,sum,ans;
int a[505],b[505];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=' '+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=10){
        for(int i=1;i<=n;i++) b[i]=i;
        do{
            sum=0;
            for(int i=1;i<=n;i++) if(sum>=a[b[i]]||s[i]=='0') sum++;
            if(n-sum>=m) ans=(ans+1)%MOD;
        }while(next_permutation(b+1,b+1+n));
        cout<<ans;
        return 0;
    }
    if(n==m){
        if(s.find('0')==string::npos&&count(a+1,a+1+n,0)==0){
            ans=1;
            for(int i=1;i<=n;i++) ans=1ll*i*ans%MOD;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
