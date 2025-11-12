#include<bits/stdc++.h>
using namespace std;
struct Node{
	int fir,sec,thi;
}a[1000000];
int n,T;
int anss;
void dfs(int ans,int x,int fir,int sec,int thi){
	if(x>n){
		anss=max(anss,ans);	
		return;
	}
	if(fir<n/2)dfs(ans+a[x].fir,x+1,fir+1,sec,thi);
	if(sec<n/2)dfs(ans+a[x].sec,x+1,fir,sec+1,thi);
	if(thi<n/2)dfs(ans+a[x].thi,x+1,fir,sec,thi+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].fir>>a[i].sec>>a[i].thi;
		}
		anss=0;
		dfs(0,1,0,0,0);
		cout<<anss<<'\n';
	}
	return 0;
}
