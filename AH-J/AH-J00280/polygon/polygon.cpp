#include<bits/stdc++.h>
using namespace std;
const int F=998244353;
int n,a[5005],cnt;
void dfs(int sum,int step,int p){
	for(int i=p;i<=n;i++){
		if(step>=3){
			if(sum+a[i]>2*a[i]){
				cnt++;
				cnt=cnt%F;
			}
		}
		dfs(sum+a[i],step+1,i+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,1,1);
	cout<<cnt%F;
	return 0;
}
