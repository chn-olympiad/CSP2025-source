#include<bits/stdc++.h>
using namespace std;
const int N=10101010;
char s[N],c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        if(c[i]<=cnt){
        cnt++;
        continue;
        }
    }
    if(n-cnt<m){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
