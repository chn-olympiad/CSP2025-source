#include<bits/stdc++.h>
using namespace std;
int n;
long long int cishu,ans;
int a[6000],q[6000],maxx;
void dfs(int st){
	if(st>=3){
		ans=0;
		for(int i=0;i<st;i++){
			ans+=q[i];
		}
		for(int i=1;i<st;i++){
			maxx=max(q[0],q[i]);
		}
		if(ans>2*maxx){
			cishu++;
		}
		return;
	}
	if(st!=0){
		for(int i=1+st;i<=n;i++){
			st++;
			q[st]=a[i];
			dfs(st);
		}
	}
	for(int i=1+st;i<=n;i++){
		q[st]=a[i];
		st++;
		for(int j=1+st;j<=n;j++){
			q[st]=a[j];
			st++;
			for(int l=1+st;l<=n;l++){
				q[st]=a[l];
				st++;
				dfs(st);
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<cishu%998244353;
	return 0;
} 
