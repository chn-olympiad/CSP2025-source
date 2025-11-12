#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505];
string s;
long long js(int x,int y){
    long long ss=0;
    ss=x-y+1;
    for(int i=x-y+2;i<=x;i++) ss=(ss*i)%mod;
    return ss;
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
cin>>s;
int nn=n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==0) nn--;
}
cout<<js(nn,m)<<endl;
return 0;
}
