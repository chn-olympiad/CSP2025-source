#include<bits/stdc++.h>
using namespace std;

int n;
int ans;
int nu[10000];
bool che(int ma,int sum){
	return ma*2<sum;
}
void dfs(int ma,int sum,int p){
	if(p==n || che(ma,sum)){
		if(che(ma,sum)){
			ans++;
		}	
	}
	for(int i=p;i<n;i++){
		sum+=nu[i];
		int lin=ma;
		dfs(max(ma,nu[i]),sum,i+1);
		sum-=nu[i];
		ma=lin;
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>nu[i];
	dfs(0,0,0);
	cout<<ans;
}
