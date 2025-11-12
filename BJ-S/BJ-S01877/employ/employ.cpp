#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c[1005];
long long o,ans=1,cnt;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(long long i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0){
            o++;
        }
    }
    if(s=="1"){
        cout<<0;
        return 0;
    }
    long long an1=1,an2=1,cnt;
    for(long long i=1;i<=n;i++){
        an1*=i;
        cnt++;
        if(cnt%3==0){
            an1%=998244353;
            an2*=an1;
        }
        if(cnt%9==0){
            an2%=998244353;
            ans*=an2;
        }
    }
    ans%=998244353;
    cout<<ans;

    return 0;
}
