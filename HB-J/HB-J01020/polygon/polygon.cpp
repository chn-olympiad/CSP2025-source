#include<bits/stdc++.h>
using namespace std;
long long num;
long long a[5010];
long long n;
void dfs(long long ma,long long sum,int ipp,int edge){
	if(edge>=3&&sum>(ma*2)){
		num++;
	}
	for(int i=ipp+1;i<=n;i++){
		dfs(max(ma,a[i]),sum+a[i],i,edge+1);
	}
	return;
}
bool k = true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],a[i],i,1);
	}
	cout<<num%998244353;
    return 0;
}
