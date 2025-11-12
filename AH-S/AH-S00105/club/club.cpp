#include<bits/stdc++.h>
using namespace std;
long long t,n,e,anss,a[100005][5],l[100005];
bool f[100005],flag;
bool cmp(long long A,long long B){
	return A>B;	
}
unordered_map<long long,unordered_map<long long,unordered_map<long long,unordered_map<long long,long long>>>>q;
long long dfs(long long dep,long b,long long c,long long d,long long ans){
if(q[b][c][d][ans]!=0){
//cout<<"111"<<"\n";
return q[b][c][d][ans];	
}
if(dep>n){
q[b][c][d][ans]=ans;
//cout<<ans<<"\n";
return ans;	
}
q[b][c][d][ans]=0;
if(b+1<=n/2)q[b][c][d][ans]=max(q[b][c][d][ans],dfs(dep+1,b+1,c,d,ans+a[dep][1]));
if(c+1<=n/2)q[b][c][d][ans]=max(q[b][c][d][ans],dfs(dep+1,b,c+1,d,ans+a[dep][2]));
if(d+1<=n/2)q[b][c][d][ans]=max(q[b][c][d][ans],dfs(dep+1,b,c,d+1,ans+a[dep][3]));
return q[b][c][d][ans];
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>t;
while(t--){
q.clear();
cin>>n;
flag=1;
for(int i=1;i<=n;i++){
cin>>a[i][1]>>a[i][2]>>a[i][3];	
if(a[i][2]!=0||a[i][3]!=0)flag=0;
}
if(flag){
for(int i=1;i<=n;i++){
l[i]=a[i][1];
}
sort(l+1,l+n+1,cmp);
anss=0;
for(int i=1;i<=n/2;i++){
anss+=l[i];
}
cout<<anss<<"\n";
}
else cout<<dfs(1,0,0,0,0)<<"\n";
}
return 0;
}
