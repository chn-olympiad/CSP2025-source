#include<bits/stdc++.h>
using namespace std;
int n,maxx;
int a[5010];
bool f[5010];
double ans;
void dfs(int k,int n,int maxx){
	if(k>maxx*2&&n>=3) ans++;
	for(int i=1;i<=n;i++){
		if(f[i]==false){
			f[i]=true;
			dfs(k+a[i],n+1,max(maxx,a[i]));
			f[i]=false;
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
	for(int i=1;i<=n;i++){
		f[i]=true;
		dfs(a[i],1,a[i]);
		f[i]=false;
	}
	int cnm=int(ans)%998;
	cnm%=244;
	cnm%=353;
	cout<<cnm*3;
	return 0;
}
