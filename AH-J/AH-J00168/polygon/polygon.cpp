#include<bits/stdc++.h>
using namespace std;
string s;
long long ans,a[1005],n,m,mod=998244353;
long long p(long long y){
long long t=2;
for(int i=1;i<=y;i++){
t*=2;
t%=mod;
}
return t;
}

bool cmp(long long A,long long B){
return A<B;	
}
unordered_map < long long , unordered_map < long long , unordered_map<long long,unordered_map<long long,unordered_map<long long,long long> > > > >q;
long long dfs(long long dep,long long sum,long long x,long long c,long long d){
if(dep>n){
if(sum>2*x&&c>=3){
//cout<<sum<<' '<<x<<"\n";
return 1;	
}
return 0;
}
if(q[dep][sum][x][c][d])return q[dep][sum][x][c][d];
if(sum>a[n]&&sum>2*x){
q[dep][sum][x][c][d]=p(n-dep);
return q[dep][sum][x][c][d];	
}
long long g=0;
g+=dfs(dep+1,sum+a[dep],a[dep],c+1,d+dep);
g%=mod;
g+=dfs(dep+1,sum,x,c,d);
g%=mod;
q[dep][sum][x][c][d]=g;
return q[dep][sum][x][c][d];
return 0;
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i];
}
sort(a+1,a+n+1,cmp);
ans=dfs(1,0,0,0,1);
cout<<ans%mod;	
return 0;
}
