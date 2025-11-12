#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,w[5005],a[5005],cnt=0;
bool check(){
	int sum=0,maxn=-1;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			sum+=w[i];
			maxn=max(maxn,w[i]);
		}
	}
	if(maxn==-1){
		return 0;
	}
	if(sum>maxn*2){
		return 1;
	}
	else return 0;
}
void dfs(int id){
	if(id==n+1){
		if(check()){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	a[id]=1;
	dfs(id+1);
	a[id]=0;
	dfs(id+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	dfs(1);
	cout<<cnt;
	return 0;
} 
