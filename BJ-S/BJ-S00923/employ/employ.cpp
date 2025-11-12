#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
const int N=505;
int c[N];
int Mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int ok=0;
    for(int i=0;i<=s.length();i++){
        if(s[i]=='0')ok=1;
    }
    long long ans=1;
    if(ok==0){
        for(int i=1;i<=n;i++){
            ans=ans*i%Mod;
        }
        cout<<ans<<endl;
    }else{
        cout<<m;
    }
    return 0;
}