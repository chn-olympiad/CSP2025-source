
#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int n,m,ans=1,a[1000];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]>=i){
            ans*=a[i];
            ans=ans%mod;
        }else{
            i--;
        }
    }
    cout<<ans;

    return 0;
    fclose(stdin);
    fclose(stdout);
}
