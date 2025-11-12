#include<bits/stdc++.h>
using namespace std;
const int N=10005;
long long ans[10],t,n,nn[N][4];
long long num,m[5],s;
void dfs(int x){
	if(x>n){
		s=max(s,num);
		return;
	}
	else{
		for(int i=1;i<=3;i++){
			if(m[i]<n/2){
				num+=nn[x][i];
				m[i]++;
				dfs(x+1);
				m[i]--;
				num-=nn[x][i]; 
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		num=0,m[5]={0},s=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>nn[i][j];
			} 
		}
		dfs(1);
		ans[k]=s;
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
