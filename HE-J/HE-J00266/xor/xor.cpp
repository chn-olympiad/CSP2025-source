#include<iostream>//±©¡¶ 
#include<cstdio>
#include<string>
using namespace std;
int a[500000+5];
int n,k;
int big = -1;
void dfs(int cur,int pos){//Œª÷√ 
	if(n-pos+1+cur<=big){
		return ;
	}
	int sum = 0;
	for(int i = pos;i<=n;i++){
		sum^=a[i];
		if(sum == k){
			for(int j = i+1;j<=n;j++){
				dfs(cur+1,j);
			}
			big = max(big,cur+1);
		}
	}
	big = max(big,cur);
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		dfs(0,i);
	} 
	cout<<big;
	return 0;
}
