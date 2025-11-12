#include<bits/stdc++.h>
using namespace std;
int n,sum,maxx,noww,bian=3;
int s[5005],a[5005];
bool vis[5005];
void dfs(int z){
	if(noww==bian){
		sum++;
		return;
	}else{
		for(int i=z;i<=n;i++){
			if(!vis[i]){
				vis[i]=true;
				z=i;
				noww++;
				dfs(z);
				vis[i]=false;
				noww--;
			}
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
		maxx=max(maxx,a[i]);
	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		for(int i=1;i<=n;i++)sum+=a[i];
		if(sum>maxx*2)cout<<1;
		else cout<<0;
	}
	for(int i=1;i<=n-2;i++){
		dfs(1);
		bian++;
	}
	cout<<sum;
	return 0;
}
