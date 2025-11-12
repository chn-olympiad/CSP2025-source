#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],f=0.p,a=1;
string s;
const long long N=998244353;
int main(){
cin>>n>>m;
cin>>s;
for(int i=0;i<n;i++)
long long cnt=0;
cin>>c[i];
for(int i=1;i<=n;i++)
a*=i;
sort(c,c+n);
while(a>0){
f=0;
for(int i=0;i<n;i++){
if(s[i]==0||c[i]<=f){
f++;
continue;
}
cnt++;
}
if(cnt>=m)
p++;
a--;
}
cout<<p%N;
return 0;
}