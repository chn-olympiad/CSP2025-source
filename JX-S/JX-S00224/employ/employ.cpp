#include<bits/stdc++.h>
using namespace std;
string s;
long long int d,e,g;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
int n,m;
cin>>n>>m;
vector<int> c(n+1);
cin>>s;
for(int i=1;i<=n;i++)
{
    cin>>c[i];
}
for(int i=1;i<=n;i++){
    d*=i;
}
for(int i=1;i<=m;i++){
    e*=m;
}
cout<<d-e;
return 0;
}
