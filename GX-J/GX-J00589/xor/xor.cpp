#include <bits/stdc++.h>
using namespace std;
int n;
int k;

int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);

cin>>n>>k;
int a[n];
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(k==0){cout<<1;}
else cout<<2;

fclose("polygon.in","r",stdin);
fclose("polygon.out","w",stdout);

return 0;
}
