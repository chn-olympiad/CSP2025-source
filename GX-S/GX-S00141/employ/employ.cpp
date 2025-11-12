#include<bits/stdc++.h>
using namespace std;
long long dp[505][505][505];
int s[505],c[505];
int main(){
    //161088479
    //46935526
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    int an=0;
    for(int i = 1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0){
            an++;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        s[i]=str[i-1]-'0';
        if(s[i]==1)sum++;
    }
    if(sum==n){
        long long summ=n;
        for(int i = 1;i<=m;i++){
            summ=(summ*(n-i))%998244353;
        }
        for(int i = m+1;i<=n;i++){
            summ=(summ*(n-i+m))%998244353;
        }
        cout<<summ;
    }
    if(m==1){
        long long summ=n;
        for(int i = 1;i<=an;i++){
            summ=(summ*(n-i))%998244353;
        }
        cout<<summ;
    }
    return 0;
}
