#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long b[5010];
long long cnt,n;
long long vis[5010];
long long s=0,maxx= 0;
void dfs(long long wz,long long l,long long ll){
	if(l >= ll+1){
		s = 0,maxx=0;
		for(long long i =1;i<l;i++){
			s+=b[i];
			maxx = max(b[i],maxx);
			if(b[i]==0) return ;
		}
		if(s>maxx*2) {
			cnt++;
			cnt%=998244353;
			return ;
		}
		return ;
	}
	for(int i =  1;i<=ll-wz+(n-ll);i++){
		b[l] = a[wz+i];
		dfs(wz+i,l+1,ll);
	}
	
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 3;i<=n;i++){
		dfs(0,1,i);
	}
	cout<<cnt;
	return 0;
}