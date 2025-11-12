#include<bits/stdc++.h>
using namespace std;
long long c,r,f,ans;
long long a[110];
long long n[110][110];
long long m[110][110];
void dfs(int y,int x,int num){//将座位打出来 
	n[x][y]=a[num];
	m[x][y]=1;
	if(a[num]==ans){
		cout<<y<<" "<<x;
		return ;
	}
	if(y>=0&&y<=r&&x<=c){
		if(m[y+1][x]==0&&(y+1)<=r) dfs(y+1,x,num+1);	
		else if(m[y-1][x]==0&&(x-1)>=0) dfs(y-1,x,num+1);
		else if(m[y][x+1]==0&&(x+1)<=c) dfs(y,x+1,num+1); 	
	}
}
int main(){
freopen("seat.in","r",stdin); 
freopen("seat.out","w",stdout);
	cin>>c>>r;
	for(int i=1;i<=c*r;i++){
		f=0;
		cin>>a[i];
		if(i==1) ans=a[i];
		for(int j=i;j>1;j--){
			if(a[j]>a[j-1]){
				f=a[j-1];
				a[j-1]=a[j];
				a[j]=f;
			}
		}
	} 
	dfs(1,1,1);
return 0;
}

