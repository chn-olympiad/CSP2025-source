#include<bits/stdc++.h>
using namespace std;

char s[105];
int c[105];
int d[105];
int ans;
int n,m;

void dfs(int day,int rq){
	if(rq>=m){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			if(s[day]=='1')	{
				d[i]=2;
				dfs(day+1,rq+1);
				d[i]=0;
			}else{
				d[i]=1;
				for(int j=1;j<=n;j++){
					c[j]--;
					if(c[j]==0){
						d[j]=1;
					}
				}
				dfs(day+1,rq);
				d[i]=0;
				for(int j=1;j<=n;j++){
					c[j]++;
					if(c[j]==1){
						d[j]=0;
					}
				}
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}

	dfs(0,0);
	cout<<ans-1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();  
	return 0;
}//awa

