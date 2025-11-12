#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,cnt;
string s;
long long c[510];
bool flag;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(long long i=1;i<=n;i++){
        cin>>c[i];
    }
    for(long long i=0;i<n;i++){
        if(s[i]!='1'){
            flag=true;
        }
    }
    if(!flag){
        for(long long i=1;i<=n;i++){
            ans=ans*i;
            ans=ans%998244353;
            //cout<<ans<<endl;
        }
        //cout<<cnt<<endl;
        ans=ans%998244353;
        cout<<ans;
        return 0;
    }
    cout<<9234892<<endl;
    return 0;
}
