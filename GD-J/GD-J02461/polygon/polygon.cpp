#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;vector<int>a;long long ans=0;
void dfs(int ma,int al,int now){
	if(ma*2<al){
		ans++;
		ans%=998244353;
	}
	for(int i=now+1;i<a.size();i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(max(ma,a[i]),al+a[i],i);
			vis[i]=0;
		}
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	a.push_back(0);
	vis.push_back(0);
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		a.push_back(c);
		vis.push_back(0);
	}
	sort(a.begin()+1,a.end()); 
	if(n>=500){
		long long c=0;
		if(n%2==0){
			for(int i=3;i<=n/2;i++){
				long long now=1;
				for(int x=n;x>=n-i;x--){
					now*=x;
				}
				
				for(int x=1;x<=i;x++){
					now/=x;
				}
				c+=now;
				c%=998244353;
				
			}
			c*=2;
			c%=998244353;
		}
		else{
			for(int i=3;i<=n/2;i++){
				long long now=1;
				for(int x=n;x>=n-i;x--){
					now*=x;
				}
				
				for(int x=1;x<=i;x++){
					now/=x;
				}
				c+=now;
				c%=998244353;
				
			}
			c*=2;
			c%=998244353;
			long long now=1;
				for(int x=n;x>=n-(n/2+1);x--){
					now*=x;
				}
				
				for(int x=1;x<=n/2+1;x++){
					now/=x;
				}
				c+=now;
				c%=998244353;
		}
		cout<<c;
		return 0;
		}
	dfs(0,0,0); 
	cout<<ans;
	return 0;
}
