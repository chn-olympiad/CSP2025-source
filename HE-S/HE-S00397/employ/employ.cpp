#include<bits/stdc++.h>
using namespace std;
int c[510];
bool v[510];
int n,m;
bool a[510];
int b[510];
string s;
long long ans=0;
void dfs(int step){
	if(step>n){
		int cnt=m;int day=0;
		for(int i=1;i<=n;i++){
			if(cnt==0) break;
			if(day<b[c[i]]&&a[i]==1){
				day=0;
				cnt--;
			}else{
				day++;
			}
		}
		if(cnt==0){
			ans++;ans%=998244353;
		} 
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
				v[i]=1;
				c[step]=i;
				dfs(step+1);
				v[i]=0;
				c[step]=0;
		}
		
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	bool ok=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			ok=0;
			a[i+1]=0;
		}else a[i+1]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(ok){
		int t=1;
		while(m--){
			t*=n;
			n--;
		}
		cout<<t;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
