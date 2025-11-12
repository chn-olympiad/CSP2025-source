#include<bits/stdc++.h>
using namespace std;
const int N=1e3*5+1;
int a[N];
int sum;
int n;
void dfs(int ma,int zongde,int shu){
	if(ma>n) return ;
	for(int i=ma;i<=n;i++){
		if(zongde+a[i]>a[i]*2&&shu>1){
			sum++;
			sum%=998244353;
		}
		dfs(i+1,zongde+a[i],shu+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<sum;
	return 0;
}
