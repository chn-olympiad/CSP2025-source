#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
const int N=5100;
int a[N];
queue<int> q;
int fang;
int n;
queue<int> p;
void dfs(int xia,int shu){
	if(xia>n){
		return ;
	}
	if(shu>=3){
		int sum=0;
		int mx=-1e7;
		while(!q.empty()){
			sum+=q.front();
			mx=max(mx,q.front());
			p.push(q.front());
			q.pop();
		}
		while(!p.empty()){
			q.push(p.front());
			p.pop();
		}
		if(sum>mx*2){
			fang++;
		}
	}
	
	q.push(a[xia]);
	dfs(xia+1,shu+1);
	q.pop();
	dfs(xia+1,shu);
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int he=a[1]+a[2]+a[3];
		int mx=max(max(a[1],a[2]),a[3]);
		if(he>mx*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	dfs(1,0);
	cout<<fang;
	return 0;
}
