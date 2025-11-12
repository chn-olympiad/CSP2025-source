#include<iostream>
#include<cstring>
using namespace std;
int n;
int a[5001],k[5001];
bool t[5001];
long long ans,pop = -10,sum;
void dfs(int x){
	if(ans > pop * 2 || x > n){
		if(ans > pop * 2){
			for(int i = 1;i < x;i++){
				cout<<ans<<" "<<pop<<" "<<x - 1<<endl; 
				sum++;
				sum %= 998244353;
			}
		}
	}
	if(x > n){
		return ;
	}
	for(int i = x;i <= n;i++){
		if(t[i] == 0){
			ans += a[i];
			pop = max(pop,(long long )a[i]);
			t[i] = 1;
			k[x] = a[i];
			//cout<<a[i]<<" ";
			dfs(x + 1);
			pop = 0
			ans -= a[i];
			t[i] = 0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",n);
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			swap(a[i],a[j]);
		}
	}
	dfs(n);
	return 0;
}