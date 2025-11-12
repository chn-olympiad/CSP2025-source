#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,m,ans=0;
string str;
int a[N],f[N];
bool vis[N];
bool check(){
	int sum=0,num=0;
	for(int i=1;i<=n;i++){
		if(f[i]<=num){
			num++;
			continue;
		}
		if(str[i-1]=='0'){
			num++;
		}else{
			sum++;
		}
	}
//	cout<<sum<<endl;
	return sum>=m;
}
void dfs(int dep){
	if(dep>n){
		ans+=check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			f[dep]=a[i];
			vis[i]=1;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
/*
3 2
101
1 1 2

*/
