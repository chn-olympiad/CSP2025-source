#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int a[1000],b[110][110];
void bfs(int x,int y,int z,int mx){
	if(x>n||y>n){
		return ;
	}
	if(mx*2<z){
		ans++;
		mx=0;
	} 
	cout<<x<<" "<<z<<" "<<mx<<'\n';
	bfs(x,y+1,z,mx);
	bfs(x+1,y+1,z+a[y],max(mx,a[y]));
}
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bfs(a[i],0,0,a[i]);
	}
	cout<<ans;
	return 0;
}
