#include <bits/stdc++.h>
using namespace std;

const int maxn=505;
const int M=998244353;

int n,m;
string t;
int a[maxn];
int ans=1;

void init(){
    cin>>n>>m;
    cin>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans*=i;
        ans%=M;
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    init();
    cout<<ans<<endl;
    return 0;
}