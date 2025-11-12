#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5050;
const int mod=998244353;
int n;
int a[N];
bool vis[N];
int answer;
void dfs(int no,int number,int length,int maxnum){
	if(number>=3&&length>maxnum*2){
		answer++;
		answer%=mod;
	}
	for(int i=no+1;i<=n;i++){
		dfs(i,number+1,length+a[i],max(maxnum,a[i]));
	}
}
signed main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i],a[i]);
	}
	answer%=mod;
	cout<<answer;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
