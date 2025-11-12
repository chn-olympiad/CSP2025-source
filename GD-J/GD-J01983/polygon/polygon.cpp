#include<bits/stdc++.h>
using namespace std;
long long m[10001],sum=0,sum1=0,j=0,maxn[10001],l,q;
void dfs(int u){
	j++;
	maxn[j]=max(maxn[j-1],m[u]);
	sum+=m[u];
	if(j>q){
		j--;
		sum-=m[u];
		return;
	}
	if(j==q){
		cout<<endl;
		if(maxn[j]*2<sum){
			sum1++;
			sum1%=998244353;	
		}
		j--;
		sum-=m[u];
		return;
	}
	for(int i=u+1;i<=l;i++){
		dfs(i);
	}
	j--;
	sum-=m[u];
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>l;
	for(int i=1;i<=l;i++){
		cin>>m[i];
	}
	for(q=3;q<=l;q++){
		for(int p=1;p<=l-2;p++) dfs(p);
	}
	cout<<sum1%998244353;
	return 0;
} 
