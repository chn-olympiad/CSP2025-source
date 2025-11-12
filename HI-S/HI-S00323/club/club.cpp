#include<bits/stdc++.h>
using namespace std;
int n,a[100001][4],maxx=0,f1[4],f2[100001],t;
void dfs(int x,int s){
	maxx=max(s,maxx);
	if(x>n)return;
	for(int i=1;i<=n;i++){
		if(f2[i]==0){
			for(int j=1;j<=3;j++){
				if(f1[j]+1<=n/2){
					f1[j]+=1;
					f2[i]=1;
					dfs(x+1,s+a[i][j]);
					f1[j]-=1;
					f2[i]=0;
				}
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		maxx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<maxx<<'\n';
	}
	
	
	return 0;
} 
