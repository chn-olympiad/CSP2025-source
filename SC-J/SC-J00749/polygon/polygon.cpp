#include<bits/stdc++.h>
using namespace std;
const int Maxn=5500;
const int q=998244353;
int h[Maxn],n=0,ans=0;
int a[Maxn];

int gmax(){
	int maxn=-1;
	for(int i=0;i<n;i++) maxn = max(maxn,a[i]);
	return maxn;
}
int gsum(){
	int sum=0;
	for(int i=0;i<n;i++) sum+=a[i];
	return sum;
}


void dfs(int join,int t,int r,bool k){
	if(t>=n||(t==n-3&&r==0)) return;
	a[t] = join;
	
	//for(int i=0;i<n;i++) cout << a[i] <<" ";
	//cout << endl;
	
	
	if(gsum()>2*gmax()&&r>=3&&k) ans=ans%q+1;
	dfs(h[t+1],t+1,r+1,true);
	dfs(0,t+1,r,false);
	return;
}
int main(){
	
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    
	cin >> n;
	for(int i=0;i<n;i++) cin >> h[i];
	
	dfs(h[0],0,1,true);
	dfs(0,0,0,false);
	cout << ans;
	return 0;
}
