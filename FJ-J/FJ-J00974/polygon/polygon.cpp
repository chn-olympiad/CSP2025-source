#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int a[5005];
long long cnt;
map<set<int>,bool>vis;
long long f(int x){
	long long ans=1;
	for(long long i=2;i<=x;i++){
		ans*=i;
		ans%=mod;
	} 
	return ans;
}
void dfs(int tot,int k,int ma,set<int> s){
	if(k>ma*2&&tot>=3&&!vis[s]){
		cnt++;
		vis[s]=1;
	}
	if(tot>n)return;
	dfs(tot+1,k,ma,s);
	s.insert(tot);
	dfs(tot+1,k+a[tot],max(ma,a[tot]),s);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n>=20){
		for(int i=3;i<=n;i++){
			cnt+=f(n)/(f(i)*f(n-i));
			cnt%=mod;
		}
	}
	else{
		set<int>aaa;
		dfs(0,0,0,aaa);
	}
	cout<<cnt/2;
	return 0;
} 
/*
	5 1 2 3 4 5
*/

