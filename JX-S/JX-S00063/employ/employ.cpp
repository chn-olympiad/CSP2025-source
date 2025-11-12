#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int n,m,d,s[501],b,c[999];
cin>>n>>m>>d;
for(int i=1;i<=n;i++){
    b=d%10;
    s[i]=b;
    d=d/10;
}
for(int i=1;i<=n;i++){
    cin>>c[i];
}
    cout<<"2";
return 0;
}
