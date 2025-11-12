#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD=998244353;
const int N=5005;

// 别挂分 plz 希望 64pts+！！！rp++!!!!! 
// N<=5000，可以O(n)/O(n^2)/O(n*∑ai) 
// 40pts：暴力DFS
// 64pts：若max ai=1，则输出C(n,3) 
// 猜测：dp[i][j]其中i表示当前下标j表示当前选择的和 

int n,a[N]; 
ll ans;

// 1/x≡x^(M-2) (mod M)

ll ny(int x){ //乘法逆元 
	ll m=MOD-2,cur=x,p=1;
	while(m){
		if(m&1){
			p=p%MOD*cur%MOD;
		}
		cur=cur%MOD*cur%MOD;
		m>>=1;
	}
	return p;
}

ll C(int x,int y){
	ll reta=1,retb=1;
	for(int i=1;i<=y;i++){
		reta=reta%MOD*(x-i+1)%MOD;
		retb=retb%MOD*i%MOD;
	}
	return reta%MOD*ny(retb)%MOD;
}

void dfs(int t,int k,int s,int maxx){
	if(t>n){
		if(k<3) return;
		if(s>2*maxx){
			ans++;
			ans%=MOD;
		}
		return;
	}
	dfs(t+1,k,s,maxx); // 不选第t根木棍 
	dfs(t+1,k+1,s+a[t],max(maxx,a[t])); // 选第t根木棍 
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool same=1; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i-1]!=a[i]) same=0;
	}
	if(same){
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
		} 
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans%MOD<<endl;
	return 0;
}

