#include <bits/stdc++.h>
using namespace std;
//int n,m;
string ti;
int c[10001];
int s[10001];
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
int n,m;
cin >>n>>m;
cin>>ti;
for(int i=1;i<=n;i++){
    cin >>s[i];
}
for(int i=1;i<=ti.size();i++){
    c[i]=ti[i]-'0';
}
long long awa=1;
long long ans=1;
for(int i=1;i<=m;i++){
    if(ans>998244353){
        ans=ans%998244353;
    }
    ans=ans*i;}

for(int i=n;i>=m;i++){
    if(ans>998244353){
        ans=ans%998244353;
    }
    ans=ans*i;
        if(ans>998244353){
        ans=ans%998244353;
    }
}
cout <<ans%998244353;
return 0;
}
