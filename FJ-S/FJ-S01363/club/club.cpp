#include<bits/stdc++.h>
using namespace std;//-O2 -std=c++14
long long T,n,ans,j1,j2,j3,rs1,rs2,rs3,wans;
void dfs(int k){
//	cout<<k-1<<" "<<rs1<<" "<<rs2<<" "<<rs3<<" "<<wans<<endl;
	if(k>n){
		ans=max(ans,wans);
		return;
	}
	cin>>j1>>j2>>j3;
	if(++rs1<=n/2){
//		rs1++;
		wans+=j1;
		dfs(k+1);
		rs1--;
		wans-=j1;
//		rs1--;
//		wans-=j1;
//		cout<<k-1<<" "<<rs1<<" "<<rs2<<" "<<rs3<<" "<<wans<<endl;
	}
	if(++rs2<=n/2){
//		rs1++;
		wans+=j2;
		dfs(k+1);
		rs2--;
		wans-=j2;
//		rs1--;
//		wans-=j1;
//		cout<<k-1<<" "<<rs1<<" "<<rs2<<" "<<rs3<<" "<<wans<<endl;
	}
	if(++rs3<=n/2){
//		rs1++;
		wans+=j3;
		dfs(k+1);
		rs3--;
		wans-=j3;
//		rs1--;
//		wans-=j1;
//		cout<<k-1<<" "<<rs1<<" "<<rs2<<" "<<rs3<<" "<<wans<<endl;
	}
	return;	
}
int main(){
	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
//		memset(a,0,sizeof(a));

		rs1=0,rs2=0,rs3=0,wans=0;
		dfs(1);
		cout<<ans<<endl;
		
//		for(int i=1,j1,j2,j3;i<=n;i++){
			
		
	}
		
	
	return 0;
}
