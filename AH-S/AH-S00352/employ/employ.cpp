#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a[505],cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cnt+=(s[i]-48);
    }
    if(cnt==n){
        long long x=1;
        for(int i=n;i>n-m;i--){
            x*=i;
            x%=N;
        }
        cout<<x;
    }
    return 0;
}
