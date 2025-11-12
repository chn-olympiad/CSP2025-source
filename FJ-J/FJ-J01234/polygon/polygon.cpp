#include<iostream>
using namespace std;
int a[5005];
bool book[5005];
int cnt;
int n;
void dfs(int step,int last_index,int sum,int maxn){
	if(maxn*2<sum) cnt++,cnt%=998244353;
	if(step>n) return;
	for(int i=last_index+1;i<=n;i++){
		if(book[i]==false){
			book[i]=true;
			dfs(step+1,i,sum+a[i],max(maxn,a[i]));
			book[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<cnt;
	return 0;
}
