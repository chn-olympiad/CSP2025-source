#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=5000+5,mod=998244353;
int n,q[N];
int mx;
ull frac[N];
ull ans=0;
inline void initfrac(){
	frac[0]=1;
	for(int i=1;i<N-3;i++){
		frac[i]=(frac[i-1]*i)%mod;
	}
	return;
}
inline ull calc(int all,int parts){
	ull res=1;
	for(int i=all-parts+1;i<n+1;i++){
		res=(res*i)%mod;
	}
	return res/frac[parts];
}
void dfs(int dep,int nowmx,int nowsum,stack<int> xl){
	if(dep==n){
		if(nowsum>2*nowmx){
			ans++;
		}
		return;
	}
	if(nowsum>2*nowmx){
		ans++;
	}
	int w=(xl.empty()?-1:xl.top());
	for(int i=w+1;i<n;i++){
		xl.push(i);
		dfs(dep+1,max(nowmx,q[i]),nowsum+q[i],xl);
		xl.pop();
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	initfrac();
	for(int i=0;i<n;i++){
		cin>>q[i];
		mx=max(mx,q[i]);
	}
	if(n<21){
		stack<int> emp;
		dfs(0,0,0,emp);
		cout<<ans;
	}
	else{
		for(int i=3;i<n+1;i++){
			ans=(ans+calc(n,i))%mod;
		}
		cout<<ans;
	}
	return 0;
}
