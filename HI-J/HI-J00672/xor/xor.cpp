#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],maxx=0;
void dfs(int i,long long s,int m){
	if(m>maxx)maxx=m;
	if(i>n)return;
	long long s1=0;
	for(int j=i;j<=n;j++){
		s1^=a[j];
		if(s1==k){
			dfs(j+1,0,m+1);
		}
		else{
			dfs(j+1,s1,m);
		}
		dfs(j+1,0,m);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	dfs(1,0,0);
	
	cout<<maxx;
	return 0;
} 
