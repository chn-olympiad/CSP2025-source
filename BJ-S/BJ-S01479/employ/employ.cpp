#include<bits/stdc++.h>
using namespace std;
const int N=101,mod=998244353;
int a[101],ans=1,n,m;
vector<int>g;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x!=0){
            g.push_back(x);
        }
    }
    int len=g.size();
    for(int i=len;i>=1;i--){
        ans=(ans*i)%mod;
    }
    cout<<ans;
    return 0;
}
