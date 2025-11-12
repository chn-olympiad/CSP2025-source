#include<bits/stdc++.h>

using namespace std;
int n,step[200010],c[200010],ans=0,m;
bool vis[200010],ji[200010];
void dfs(int d){
	if(d==n+1){
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++){
			//cout<<step[i]<<":"<<c[step[i]]<<" "<<tot<<endl;
			if(!vis[i] or cnt>=c[step[i]]){
				cnt++;
			}else tot++;
			if(tot==m){
				//cout<<endl;
				ans++;
				return;
			}
		}//cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!ji[i]){
			ji[i]=1;
			step[d]=i;
			dfs(d+1);
			ji[i]=0;
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		vis[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	return 0;
}

