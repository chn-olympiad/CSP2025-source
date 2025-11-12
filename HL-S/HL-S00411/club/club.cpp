#include<bits/stdc++.h>
using namespace std;

int n,t;
int a[20005][5];
int dx;	
int f=100000;
void dfs(int x){
	if(f>x){
		f=x;
		
	}
	else
		return ;
	for(int i=1;i<=3;i++)
			for(int j=n/2;j>0;j--)
				dx=a[i][j]+a[i][j+1];
	if(dx>f)
		dfs(dx);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				dfs(0);
			}	
		}
		cout<<f;
	}
	return 0;
}
