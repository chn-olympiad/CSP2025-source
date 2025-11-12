#include <bits/stdc++.h>
using namespace std;
const int N=998244353,M=5010;
long long n,a[M],sum,i;
void dfs(long long x,long long s,long long num,long long max_){
	if(num>n) return ;
	if(x==0){
		if(s>a[num]*2){
			sum=(sum+1)%N;
		}
		s-=a[num];
		x--;
		return ;
	}
	if((n-x)>1) dfs(x,s,num+1,max_);
	max_=max(max_,a[num]);
	dfs(x-1,s+a[num],num+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=3;i<=n;i++){
		dfs(i,0,1);
	}
	printf("%d",sum);
}
