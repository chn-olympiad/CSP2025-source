#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
using namespace std;
int n,m;
long long ans=1;
string s;
int c,t;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(c==0) t++;
    }
    if(n-t<m){
        cout<<0;
        return 0;
    }
    for(ll i=1;i<=n-t;i++){
        ans=i*ans%998244353;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
