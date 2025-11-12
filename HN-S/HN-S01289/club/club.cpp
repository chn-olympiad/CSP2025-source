#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
long long a[N][4],mx,cnt[4];
bool st[N][4];
void dfs(int x,long long sum){
	if(x==n+1){
		mx=max(mx,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(!st[x][i]&&cnt[i]+1<=n/2){
			st[x][i]=1;
			cnt[i]++;
			dfs(x+1,sum+a[x][i]);
			st[x][i]=0;
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		mx=0;
		memset(st,0,sizeof(st));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<mx<<"\n";	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
