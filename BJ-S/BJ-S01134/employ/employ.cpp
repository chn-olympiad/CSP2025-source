#include <bits/stdc++.h>
using namespace std;

const int N=510,mod=998244353;
int n,m,s[N],c[N];
long long ans=1;
bool flag=1;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char in;
        cin>>in;
        s[i]=in-'0';
        if(s[i]!=1){
            cout<<0;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=n;i>=1;i--)ans=(ans*i)%mod;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
