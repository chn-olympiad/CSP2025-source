#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],vis[505],a[505],ans;
string s;
void dfs(int l){
	if(l==n){
		int out=0,cnt=0;
		for(int i=1;i<=l;i++){
			//cout<<a[i]<<" ";
			if(c[a[i]]<=out){out++;continue;}
			if(s[i]=='1')cnt++;
			else out++;
		}
		//cout<<endl;
		ans+=(cnt>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[l+1]=i;
			dfs(l+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	s=' '+s;
	if(n<=18){
		dfs(0);
		cout<<ans<<endl;
	}else cout<<0<<endl;
	return 0;
}
