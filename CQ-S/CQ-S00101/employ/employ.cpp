#include<bits/stdc++.h>

using namespace std;

const int mo=998244353;

int n,m;
string s;
int c[505],a[505];
bool vis[505];
int ans;

void dfs(int i){
	
	if(i>n){
		int cnt=0,sum=0;
//		for(int k=1;k<=n;k++)cout<<a[k]<<' ';
//		cout<<'\n';
		for(int k=1;k<=n;k++){
			if(cnt>=c[a[k]]){cnt++;continue;}
			if(s[k-1]=='0'){cnt++;continue;}
			sum++;
		}
//		cout<<cnt<<' '<<sum<<'\n';
		if(sum>=m)ans++,ans%=mo;
		return;
	}
	
	for(int k=1;k<=n;k++){
		if(vis[k]==false){
			vis[k]=true;
			a[i]=k;
			dfs(i+1);
			vis[k]=false;
		}
	}
	
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	
	for(int i=1;i<=n;i++)cin>>c[i];
	
	if(m==1){
		int kk=0;
		for(;kk<s.size()&&s[kk]=='0';kk++);
		for(int i=1;i<=n;i++)if(c[i]>kk)ans++;
		cout<<ans;
		return 0;
	} 
	
	dfs(1);
	
	cout<<ans;
	
	return 0;
	
}
