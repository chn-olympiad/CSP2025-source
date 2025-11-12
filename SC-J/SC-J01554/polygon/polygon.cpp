#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],f[5005],ans;
void dfs(long long g,long long step,long long cnt,long long maxx,long long w){
	if(step>=g){
		if(cnt>2*maxx){
			ans++;
		}
		return;
	}
	for(int i=w+1;i<=n;i++){
		if(f[i]==0){
			f[i]==1;
			dfs(g,step+1,cnt+a[i],max(maxx,a[i]),i);
			f[i]==0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0,0); 
	}
	cout<<ans;
	return 0;
} 