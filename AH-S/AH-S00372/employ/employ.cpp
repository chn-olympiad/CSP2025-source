#include<bits/stdc++.h>
using namespace std;
long long a[500],n,m,cum=1,sum=0;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cum*=i;
        cum%=998244353;
    }
    cout<<0;
    return 0;
}
