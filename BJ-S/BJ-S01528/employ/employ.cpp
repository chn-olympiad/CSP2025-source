#include<bits/stdc++.h>
using namespace std;
int n,m;
int nx[505];
const long long MOD=998244353;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("empoly.in","r",stdin);
    freopen("empoly.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>nx[i];
    }
    sort(nx+1,nx+n,cmp);
    bool flag=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            flag=false;
        }
    }
    if(flag){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*i%MOD;
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        int cnt=0;
        int jc=1;
        int ans=0;
        for(int i=1;i<=n-1;i++){
                jc=jc*i%MOD;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                for(int i=1;i<=n;i++){
                    if(nx[i]>cnt){
                        ans=(ans+jc)%MOD;
                    }
                }
            }
            cnt++;
        }
        cout<<ans;
    }
    return 0;
}
