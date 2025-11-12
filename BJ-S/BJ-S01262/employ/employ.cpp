#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
const int maxn=505;
int n,m,c[maxn],sum[maxn];
bool st[maxn];
string s;

long long jiech(int x){
    int ret=1;
    for(int i=1;i<=n;i++){
        ans=(ans*i)%mod;
    }
    return ans;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.length();i++){
        st[i+1]=(int)(s[i]-'0');
        if(st[i+1]==1) cnt++;
    }
    for(int i=1;i<=n;i++){
        for(int j=)
    }
    bool flag=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]<m) flag=1;
    }
    
    if(cnt==n) cout<<jiech(n)<<endl;
    else if(cnt<m) cout<<0<<endl;
    else if(!flag) cout<<jiech(n)<<endl;
    else {
        cout<<jiech(n)<<endl;
        
    }
    return 0;
}
