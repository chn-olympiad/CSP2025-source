//GZ-S00316 毕节东辰实验学校 王子晨 
#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
vector<int> c(501);
int ans;
bool emp[501];
void dfs(int dep,int fal,int suc){
	if(n-m<fal){
		return;
	}
	if(suc>=m){
		int a=1;
		for(int i=n-dep;i>0;i--){
			a*=i;
		}
		ans+=a;
		return;
	}
	if(dep==n){
		if(suc>=m){		 
		ans++;
		ans=ans%998244353;	
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(emp[i]==false){
			emp[i]=true;
			if(fal<c[i]){
				if(s[dep]=='1'){
					dfs(dep+1,fal,suc+1);	
				}else{
					dfs(dep+1,fal+1,suc);
				}
				
			}else{
				dfs(dep+1,fal+1,suc);
			}
			emp[i]=false;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0,0,0);
	cout<<ans; 
	return 0;
}
