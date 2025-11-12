#include<bits/stdc++.h>
using namespace std;
vector<unsigned long long>a;
unsigned long long n,k,out=0;
void dfs(const unsigned long long now_i,const unsigned long long now_have_ok, unsigned long long now_xor){
	if(now_i>=n){
		if(now_xor==k){
			out=max(now_have_ok+1,out);
		}
		else out=max(now_have_ok,out);
		return;
	}
	if(now_xor==k){
	//okay
	out=max(now_have_ok+1,out);
	dfs(now_i+1,now_have_ok+1,a[now_i]);
	dfs(now_i+1,now_have_ok+1,-1);
	return;
	}

	if(now_xor==-1)now_xor=0;
	dfs(now_i+1,now_have_ok,now_xor xor a[now_i]);
	dfs(now_i+1,now_have_ok,-1);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	a.resize(n);
	for(unsigned long long i=0;i<n;i++)cin>>a[i];
	
	dfs(0,-1,0);
	cout<<out;
	return 0;
}
//if k==0,it is broken!!!
