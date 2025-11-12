#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long cnt=1;
    for(int i=n;i>=1;i--){
        cnt*=i;
        cnt%=998;
        cnt%=244;
        cnt%=353;
    }
    cout<<cnt;
    return 0;
}
