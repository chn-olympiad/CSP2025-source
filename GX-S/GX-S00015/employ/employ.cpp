#include<bits/stdc++.h>
using namespace std;
int a[100000];
string s;
int ans;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
int n,m;
cin>>n>>m;
cin>>s;
for(int i=0;i<n;++i)
    cin>>a[i];
for(int i=n-1;i>=0;--i)
    ans+=i;
cout<<ans;
return 0;
}
