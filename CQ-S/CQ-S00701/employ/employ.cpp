#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ff=1;
string spp;
long long s[505];
long long a[505];
long long v[505];
long long vis[505];
long long c[505][505];
const long long ft=998244353;
void fo(){
	for(long long i=0;i<=501;i++){
		c[0][i]=1;
	}
	for(long long i=1;i<=501;i++){
		for(long long j=i;j<=501;j++){
			c[i][j]=c[i-1][j-1]+c[i][j-1];
			c[i][j]%=ft;
		}
	}
	return;
}
void dfs(long long u){
	if(u>n){
		long long st=0,tmp=0;
		for(long long i=1;i<=n;i++){
			if(s[i]==1){
				if(st>=a[i]){
					st++;
				}else{
					tmp++;
				}
			}else{
				st++;
			}
		}
		if(tmp>=m){
			sum++;
			sum%=ft;
		}
		return;
	}else{
		for(long long i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				v[u]=i;
				dfs(u+1);
				v[u]=0;
				vis[i]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fo();
	cin>>n>>m;
	cin>>spp;
	spp=" "+spp;
	for(long long i=1;i<=n;i++){
		s[i]=(spp[i]-'0');
		if(s[i]==0){
			ff=0;
		}
	}
	if(n<=10){
		dfs(1);
		cout<<sum;
	}else if(ff==1){
		sum=1;
		for(long long i=1;i<=n;i++){
			sum=sum*i;
			sum%=ft;
		}
		cout<<sum;
	}else{
		dfs(1);
		cout<<sum;
	}
	return 0;
}

