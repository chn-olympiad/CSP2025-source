#include <bits/stdc++.h>
using namespace std;
int n,sum;
void dfs(int x,int y){
	
	if(x==n){
		return;
	}
	sum++;
	
}
int main(){
	cin>>n;
	dfs(1,1);
}
