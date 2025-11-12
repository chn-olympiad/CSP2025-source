#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
int a[50015]; 
void dfs(int x,int ma,long long s,int b){
	if(b>=3){
		if(s>ma*2){
			sum++;
			sum%=998244353;
		}
	}
	if(b>n)return;
	for(int i=x;i<=n;i++){
		dfs(i+1,max(ma,a[i]),s+a[i],b+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<sum%998244353;
	return 0;
} 
