#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
long long n,m,p=1;
cin>>n>>m;
for(int i=n;i>=m;i--){
p=p*i;
}
cout<<p/2/998244353;
return 0;
}


