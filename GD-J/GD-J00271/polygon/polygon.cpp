#include<bits/stdc++.h>
using namespace std;
int vis[25],n,t;
string a[10000000];
void dfs(int depth,string ans){
	if(depth==n){
		a[t++]=ans;
		return ;
	}
	for(int i=0;i<=1;i++){
		if(vis[depth]==0){
			vis[depth]=1;
			dfs(depth+1,ans+(to_string(i)));
			vis[depth]=0;
		}
	}
}
int f[50];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	dfs(0,"");
	long long sum=0;
	for(int i=0;i<n;i++)cin>>f[i];
	for(int i=0;i<t;i++){
		int s=0,ma=0;
		for(int j=0;j<n;j++){
			if(a[i][j]=='1'){
				ma=max(f[j],ma);
				s+=f[j];
			}
		}
		if(s>ma*2){
			sum++;
		}
	}
	cout<<sum%99824453;
	return 0;
} 
