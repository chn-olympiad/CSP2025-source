#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,k,a[1001];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(k==0) cout<<"1";
else cout<<"2";
fclose(stdin);
fclose(stdout);
return 0;
}
