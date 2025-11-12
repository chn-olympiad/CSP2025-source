#include<bits/stdc++.h>
using namespace std;
long long n,ans,c[505],m;
string s;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>m;
cin>>s;
for(int i=1;i<=n;i++){
cin>>c[i];
ans=ans*i;
ans=ans%998244353;
}
cout<<ans;
fclose(stdin);
fclose(stdout);
return 0;
}
