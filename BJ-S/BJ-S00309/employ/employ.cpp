#include <bits/stdc++.h>
using namespace std;

const long long P=998244353;

long long n,m,a[505];

long long ans;

string s;

int main(){

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m>>s;

    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    //A
    bool aflag=0;
    for(int i=0;i<=s.size();++i){
        if(s[i]==0)aflag=1;break;
    }
    if(!aflag){
        ans=1;
        for(int i=n;i>=1;--i){
            ans=(ans*i)%P;
        }
        cout<<ans<<endl;
    }
    return 0;
}
