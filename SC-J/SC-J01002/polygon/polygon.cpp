#include<bits/stdc++.h>
using namespace std;
int n,d=0;
int a[10101];
int b[10101];
int dfs(int x,int y,int z,int c){
	if(z>=3&&c*2<y) {
		d++;
	}
	for(int i = x+1; i <= n; i++){
		if(b[i]==0){
			b[i]=1;
			dfs(i,y+a[i],z+1,max(c,a[i]));
			b[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	dfs(0,0,0,0);
	cout<<d;
	cin>>n;
	return 0;
}