#include<bits/stdc++.h>
using namespace std;
int a,r,e;
long long s=1;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>a>>r;
for(int i=2;i<=a;i++){
s=(s*i)%998244353;
} 
cout<<s<<endl; 
fclose(stdin);
fclose(stdout);
return 0;
}
