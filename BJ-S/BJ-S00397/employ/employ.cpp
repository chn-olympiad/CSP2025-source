#include<bits/stdc++.h>
using namespace std;
long long n,m,r[510],p[510][510],cn[510],nm=998244353,ans;
string k;
int main(){
    freopen("day1.in","r",stdin);
    freopen("day1.out","w",stdout);
    cin>>n>>m;
    cin>>k;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        cn[r[i]]++;
    }
    for(int i=1;i<=500;i++) cn[i]+=cn[i-1];
    p[0][0]=1;
    for(int i=1;i<=n;i++) for(int j=0;j<=n;j++){
        p[i][j]=(p[i-1][j]*(n-cn[j]-i+cn[j-1])%nm+p[i-1][j-1]*(cn[j]-cn[j-1])%nm)%nm;
    }
    for(int i=n-m;i<=n;i++) ans=(ans+p[n][i])%nm;
    cout<<ans<<endl;
    return 0;
}