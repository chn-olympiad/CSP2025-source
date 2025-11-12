#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=1;
int a[501],t[501],k;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==n){
        bool a1=0,a2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='1'){
                a1=1;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                a2=1;
                break;
            }
        }
        if(a1==1||a2==1) cout<<0;
        for(int i=1;i<=n;i++) t[a[i]]++;
        for(int i=1;i<=n;i++){
        cnt*=i;
        cnt%=998244353;
        }
        cout<<cnt;
    }
    return 0;
}

