#include<bits/stdc++.h>
using namespace std;
int ans[11][11];
bool b=0,z=0;
int a[101],a1[101];
int n,m;
int t,k=0; 
void dfs(int x,int y){
	if(k==(n*m)){
		ans[x][y]=a[k];
		return;
	}
	else if(x==n&&z!=0){
		
		k++;
		ans[x][y]=a[k];
		b=1;
		z=0;
		dfs(x,y+1);
		
	}
	else if(x==1&&z!=0){
		k++;
		ans[x][y]=a[k];
		b=0;
		z=0;
		dfs(x,y+1);
		
	}
	else if(b==0){
		k++;
		z=1;
		ans[x][y]=a[k];
		dfs(x+1,y); 
	}
	else if(b==1){
		k++;
		z=1;
		ans[x][y]=a[k];
		dfs(x-1,y); 		
	}
	

}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a1[i];
	}
	t=a1[1];
	//cout<<t;
	sort(a1+1,a1+1+n*m);
	//for(int i=1;i<=(n*m);i++)cout<<a1[i]<<' ';
	for(int i=1;i<=(n*m);i++){
		a[n*m-i+1]=a1[i];
	}
	//for(int i=1;i<=(n*m);i++)cout<<a[i]<<' ';
	dfs(1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<ans[i][j]<<' '; 
			if(ans[i][j]==t)cout<<j<<' '<<i;
		}
		//cout<<endl;
	}
	return 0;
}
