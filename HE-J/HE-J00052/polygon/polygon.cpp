#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int MOD=998244353;
int n,a[N],sum,b[N],l;
bool flag[N];
void pd(int k){
	int s=0,ss=-10;
	for(int i=1;i<=k;i++){
		s+=b[i];
		ss=max(ss,b[i]);
	}
	if(ss*2<s){
		sum++;
		sum%=MOD;
	}
}
void dfs(int id,int now){//id Ò»¹² now Ñ¡ 
	if(id==now+1){
		pd(id);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=true;
			b[now]=a[i];
			dfs(id,now+1);
			flag[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=3;j<=n;j++){
		dfs(j,1);
	}
	cout<<sum/2;
	return 0;
}
