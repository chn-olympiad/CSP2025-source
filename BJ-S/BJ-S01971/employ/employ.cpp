#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    char a[510];
    int b[510];
    cin>>a;
    for(int i = 1;i <= n;i++){
        cin>>b[i];
    }
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(a[i] == '1'){
            cnt++;
        }
    }
    long long ans = 1;
    for(int i = n;i >= cnt;i--){
        ans *= i;
        ans%=998244353;
    }
    cout<<ans<<endl;
    return 0;
}
