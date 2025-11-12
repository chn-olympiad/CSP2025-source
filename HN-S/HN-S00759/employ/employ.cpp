#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
bool op[505];
int a[505];
bool vis[505];
int box[505];
int ans=0;
void dfs(int step){
	if(step>n){
		int M=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=a[box[i]]){
				if(!op[i]){
					cnt++;
				}else{
					M++;
				}
			}else{
				cnt++;
			}
		}
		if(M>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			box[step]=i;
			vis[i]=1;
			dfs(step+1);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	string s;
	cin>>s;
	s=" "+s;
	bool flag=1;
	for(int i=1;i<=n;i++){
		op[i]=s[i]-'0';
		flag&=op[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
