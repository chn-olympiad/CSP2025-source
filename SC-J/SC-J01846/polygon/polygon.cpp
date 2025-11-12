#include <bits/stdc++.h>
using namespace std;
int a[5010],n,i,k;
bool f[5010];
void print(){
	for(int i=1;i<=n;i++)
		if(f[i]==true) cout<<a[i]<<" ";
	cout<<'\n';
}
void dfs(int sum,int ma,int num,int c){
	if(num==i&&sum>ma*2){
		k=(k+1)%998244353;
		//print();
		return;
	}else{
		for(int j=c;j<=n;j++){
			if(!f[j]){
				f[j]=true;
				dfs(sum+a[j],max(ma,a[j]),num+1,j+1);
				f[j]=false;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=3;i<=n;i++) dfs(0,0,0,1);
	cout<<k;
	return 0;
}