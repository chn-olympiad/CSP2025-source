#include <bits/stdc++.h>
using namespace std;
const int max_=1e2+5;
int n,m,a[max_],f[max_],rk[max_];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int k,bool f){
	if(k==1){
		cout<<x<<' '<<y;
		return;
	}
	if(f){
		if(y==n){
			dfs(x+1,y,k-1,0);
		}else{
			dfs(x,y+1,k-1,1);
		}
	}else{
		if(y==1){
			dfs(x+1,y,k-1,1);
		}else{
			dfs(x,y-1,k-1,0);
		}
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		f[i]=a[i];
	}
	sort(f+1,f+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(f[i]==a[j]){
				rk[j]=i;
			}
		}
	}	
	dfs(1,1,rk[1],1);
	return 0;
}
