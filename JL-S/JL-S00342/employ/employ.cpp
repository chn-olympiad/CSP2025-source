#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
long long n;
cin>>n;
string s;
cin>>s;
long long m=1;
long long a=n;
for(long long i=1;i<=n;i++){
    long long h;
    cin>>h;
    if(h==0)
        a--;
}
for(long long i=1;i<=a;i++){
    m*=i;
    m%=998244353;
}
cout<<m;
}
