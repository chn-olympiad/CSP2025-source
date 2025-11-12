#include<bits/stdc++.h>
using namespace std;
long long n,m,qwe[20],ans;
bool zai[20];
string A;
void check(string P){
	int failed=0;
	for(int i=0;i<=n-1;i++){
		if(A[i]=='0'||failed>=qwe[P[i]-'0']){
			failed++;
		}
	}
	if(failed<=n-m) ans=(ans+1)%998244353;
	return ;
}
void dfs(int d,string P){
	if(d==n){
		check(P);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(zai[i]==0){
			zai[i]=1;
			string p=P+(char)('0'+i);
			dfs(d+1,p);
			zai[i]=0;
		}
	}
	return ;
}
int main(){
	//冷静下来  我相信你 
	//卡过小数据啊！ 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>A;
	for(long long i=1;i<=n;i++){
		cin>>qwe[i];
	}
	dfs(0,"");
	cout<<ans;
	return 0;
}
