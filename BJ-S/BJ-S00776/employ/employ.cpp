#include<bits/stdc++.h>
using namespace std;
long long n,m,que[3],ans,a[600],box[600];
long long MOD=998244353;
long long qpl(long long a){
    long long num=a;
    while(--a){
        num*=a;
        num%=MOD;
    }
    return num;
}
//1 1 2 3
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        char x;
        cin >> x;
        que[x-'0']++;
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
        box[a[i]]++;
    }
    if(que[1]==n or n==m){
        ans=n;
        while(--n){
            ans*=n;
            ans%=MOD;
        }
        cout << ans;
        return 0;
    }
    if(m==1){
        ans=1;
        for(int i=0;i<=500;i++){
            ans*=n;
            ans%=MOD;
            n-=box[i]+1;
        }
        cout << ans;
        return 0;
    }
}
