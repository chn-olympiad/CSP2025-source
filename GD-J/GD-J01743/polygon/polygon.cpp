#include<bits/stdc++.h>
using namespace std;
int a[5005],n;
int v[5005],ans;
void dfs(int d,int s,int ii){
	if(d>s){
		int sum=0;
		int maxx=-1;
		for(int i=1;i<=s;i++){
			maxx=max(maxx,v[i]);
			sum+=v[i];
		}
		if(sum>maxx*2){
			ans++;
		}
		return;
	}
	for(int i=ii;i<=n;i++){
		v[d]=a[i];
		dfs(d+1,s,i+1);
		v[d]=0;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,i,1);
	}
	cout<<ans;
	return 0;
}
