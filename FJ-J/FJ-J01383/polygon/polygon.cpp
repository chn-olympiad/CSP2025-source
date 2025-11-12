#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005];
long long ans;
bool f=0;
void dfs(int x,int y,int z,int k){//x表示当前第几个,y表示一共选几个,z表示最长,k表示总长 
	if(k>2*z && y>=3){
		ans++;
	}
	if(x==n){
		return;
	}
	dfs(x+1,y+1,max(z,a[x+1]),k+a[x+1]);
	dfs(x+1,y,z,k);
}
void dffs(int x,int y){
	if(y>=3){
		ans++;
	}
	if(x==n){
		return;
	}
	dffs(x+1,y+1);
	dffs(x+1,y);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0){
		dffs(1,1);
		cout << ans%N << endl;
		return 0;
	}
	dfs(1,1,a[1],a[1]);
	cout << ans%N;
	return 0;
} 
