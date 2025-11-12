#include<bits/stdc++.h>
using namespace std;
int t,n,member[2000][5],b[2000],halfn,timee;
int flag[5];
int maxx,summ;
void dfs(int step){
	if(step==n+1){
		if(maxx<=summ) maxx=summ;
		return; 
	}
	for(int i=1;i<=3;i++){
		if(flag[i]<halfn){
			flag[i]++;
			summ+=member[step][i];
			dfs(step+1);
			summ-=member[step][i];
			flag[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		halfn=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>member[i][j];
			}		
		}
		if(n>=30) {
			maxx=0;
			for(int i=1;i<=n;i++){
				maxx+=member[i][1];
			} 
		}else{
			maxx=0;
			dfs(1);
		}
		cout<<maxx<<endl;
		
	}
	return 0;
} 
