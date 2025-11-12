#include<bits/stdc++.h>
using namespace std;
int n,m;
int di[600];
const int MOD = 998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char s;
        cin>>s;
        di[i]=s-'0';
    }
    int ccnt=0;
    for(int i=1;i<=n;i++){
        int c;
        cin>>c;
        if(c==0) ccnt++;
    }
    if(ccnt>(n-m+1)){
        cout<<0;
        return 0;
    }
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=(ans*i)%MOD;
    }
    cout<<ans;
    return 0;
}
