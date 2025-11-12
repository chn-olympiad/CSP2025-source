#include<bits/stdc++.h>
using namespace std;
long long a=1,p=998244353,n,k;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>k;
for(long long i=1;i<=n;i++){
a=a*i%p;
}
cout<<a;
return 0;
} 
