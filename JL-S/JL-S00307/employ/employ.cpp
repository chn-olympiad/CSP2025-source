#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
bool cmp(int x,int y){
    return x>y;
}
long long A(int a){
    long long ret=1;
    for(int i=1;i<=a;i++){
        ret*=i;
        ret%=998244353;
    }
    return ret;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0) cnt++;
    }
    long long ans=0;
    n-=cnt;
    ans=A(m);
    ans*=A(n-m);
    ans%=998244353;
    cout<<ans;
    return 0;
}
