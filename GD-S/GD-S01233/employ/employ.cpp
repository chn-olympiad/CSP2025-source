#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int N=505;
const int p=998244353;
string s;
int a[N];
int h[N];
bool vis[N];
int n=0,m=0;
long long ans=0;
void solve1(){
	int endur=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'||endur>=h[i]){
			endur++;
			continue;
		}
		else{
			cnt++; 
		}
	}
	if(cnt>=m){
		ans++;
//		for(int i=1;i<=n;i++){
//			cout<<h[i]<<" ";
//		} 
//		cout<<cnt<<" cntt\n";
	}
	if(ans>=p)ans-=p;
	return ;
}
long long jc(long long k){
	long long cj=1ll;
	for(int i=1;i<=n;i++){
		cj=(cj*i)%p;
	}
	return cj%p;
}
void dfs(int dep){
	if(dep==0){
		solve1();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		h[dep]=a[i];
		dfs(dep-1);
		vis[i]=0;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=18){
		dfs(n);
		cout<<ans;
		return 0;
	}
	else if(n==m){
		bool flag=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				flag=0;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]<=0){
				flag=0;
				break;
			}
		}
		if(flag==0){
			cout<<"0";
			return 0; 
		}
		else{
			cout<<jc(n)%p;
			return 0;
		}
	}
//	else if(m==1){
//		
//	}
	return 0;
}
