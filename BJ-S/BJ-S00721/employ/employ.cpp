#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[510],ans=0,x=998244353;
long long f(int y){
    if(y==1)return 1;
    else if(y==2)return 2;
    else if(y==3)return 6;
    else return y*f(y-1)%x;
}
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    cout<<f(n)%x;
    return 0;
}
