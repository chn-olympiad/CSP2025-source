#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m,s[505],t[505],num;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
        cin>>t[i];
        if(t[i]) num++;
    }
    for(int i=1;i<=n;i++)
        if(s[i]==0){
            cout<<0;
            return 0;
        }
    if(num<m){
        cout<<0;
        return 0;
    }
    else{
        long long ans=1;
        for(int i=2;i<=num;i++){
            ans=(ans*i)%N;
        }
        cout<<ans;
    }
    return 0;
}
