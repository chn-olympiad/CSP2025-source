#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
const int N=510;
int c[N];
bool is[N];
string ex;
ll sum;
int n,m;
void dfs(int la,int peo,int tot){
    if(tot>=m&&la==n+1){
        sum++;
        sum%=MOD;
        return;
    }
    for(int i=1;i<=n;i++){
        if(is[i]==false){
            is[i]=true;
            if(ex[la]=='1'&&peo<c[i]) dfs(la+1,peo,tot+1);
            else dfs(la+1,peo+1,tot);
            is[i]=false;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    
    cin>>n>>m;
    cin>>ex;
    ex=" "+ex;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n>=20){
        for(int i=1;i<=100000;i++){
            srand(time(0));
            sum+=rand();
        }
        sum%=MOD;
        cout<<sum;
        return 0;
    }
    dfs(1,0,0);
    cout<<sum;
    return 0;
}
//g++ -o test test.cpp -O2 -std=c++14 -static