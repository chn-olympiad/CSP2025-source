#include<iostream>
#include<algorithm> 
using namespace std;
int sum,n,a[100010];
void dfs(int x,int i,int s,int ma){
	if(x == 0){
		if(ma * 2 < s){
			sum++;
			sum %= 998244353;
		}
		return;
	}
	for(;i < n - x + 1;i++)
		dfs(x - 1,i + 1,s + a[i],a[i]);
}
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i = 0;i < n;i++)
		cin>>a[i];
	for(int i = 3;i <= n;i++)
		dfs(i,0,0,0);
	cout<<sum;
	return 0;
}