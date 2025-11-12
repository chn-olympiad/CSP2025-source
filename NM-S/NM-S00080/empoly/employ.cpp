#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int p[1010];
long long pl(int n){
    long long sum=1;
    for(int i=1;i<=n;i++){
        sum*=i;
    }
    return sum%998244353;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    int x=n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        if(p[i]<=0){
            x--;
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]-'0'!=1&&x!=n){
            cout<<0;
            return 0;
        }
    }
    long long ans=pl(x);
    cout<<ans;
    return 0;
}
