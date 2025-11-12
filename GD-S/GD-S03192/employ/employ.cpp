#include <bits/stdc++.h>
using namespace std;
int n,m,c[50005],ans=0;
char t;
bool hd[50005],md[50005];
void dfs(int l,int nw){
	if(l>=m&&nw>=n) {
		ans=(ans+1)%998244353;
		return;
	}
	for(int i=0;i<n;i++){
		if(!md[i]){
			md[i]=1;
			if(nw-l<c[i]){
				dfs(l+(int)hd[nw],nw+1);
			}else{
				dfs(l,nw+1);
			}
			md[i]=0;
		}
	} 
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t;
		hd[i]=(t=='1');
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
