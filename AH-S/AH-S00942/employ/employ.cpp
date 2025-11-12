#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
string s;
int c[N],t;
long long ans;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    ans=1;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        t+=int(s[i]-'0');
    }
    int p=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0)p++;
    }
    //cout<<t<<"\n";
    if(t==n){
        if(n-p<m)ans=0;
        for(int i=n;i>=p+1;i--){
            ans*=i;
            ans%=mod;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
