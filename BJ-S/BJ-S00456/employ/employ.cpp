#include<bits/stdc++.h>
using namespace std;

const int N=505;
const long long mod=998244353;

int n,m;
string s;
long long c[N];
long long ans=0;
long long ans1;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin >> s;
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    for(int i=m;i<=n;i++){
        ans1=1;
        for(int j=n;j>n-m;j--){
            ans1=(ans1*j)%mod;
        }
        ans=(ans+ans1)%mod;
    }
    cout << ans;
    return 0;
}
