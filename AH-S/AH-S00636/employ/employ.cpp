#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5,mod=998244353;
long long n,t,ans=1,m,c[N];
char a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    t=n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0)t--;
    }
    //cout<<endl;
    for(int i=t;i>=1;i--){
        ans=ans*i%mod;
        //cout<<ans<<endl;
    }
    cout<<ans%mod;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
