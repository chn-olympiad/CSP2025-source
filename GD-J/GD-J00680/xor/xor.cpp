#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10100],b[10100][10100],ans;
int yhh(int x,int y){
	int cu=a[x];
	for(int i=x+1;i<=x+y;i++){
		cu=cu^a[i];
	}
	if(cu==k){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i][0]=yhh(i,0);
		if(b[i][0]==1){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j+i<=n;j++){
			b[i][j]=max(b[i+j][0]+b[i][j-1],yhh(i,j));
		}
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,b[1][i]+b[2+i][n-2-i]);
	}
	cout<<ans;
	freopen("xor.out","w",stdout);
}

