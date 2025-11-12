#include<bits/stdc++.h>
using namespace std;
int t,n,a[10001][4],dp[101][101][101][101],res=0,siz[4],p[101],cnt=1,tmp[100001],tmp2[100001];
void dfs(int i,int s){
	if(i>n){
		res=max(res,s);
//		for(int i=1;i<cnt;i++)cout<<p[i]<<' ';
//		cout<<s<<'\n';
		return;
	}
	if(i<=100&&s<dp[i][siz[1]][siz[2]][siz[3]]){
		return;
	}
	dp[i][siz[1]][siz[2]][siz[3]]=s;
	
	for(int j=1;j<=4;j++){
		if((siz[j]+1)>n/2)continue;
		siz[j]++;
		p[cnt++]=a[i][j];
		dfs(i+1,s+a[i][j]);
		siz[j]--;
		p[--cnt]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool flag1=1,flag2=1;
		res=0;
		cin>>n;
		memset(siz,0,sizeof(siz));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0)flag1=0;
			if(a[i][3]!=0)flag2=0;
		}
		if(flag1&&n>=1001){
			for(int i=1;i<=n;i++){
				tmp[i]=a[i][1];
			}
			sort(tmp+1,tmp+1+n,greater<int>());
			for(int i=1;i<=n/2;i++){
				res+=tmp[i];
			}
		}else if(flag2){
			for(int i=1;i<=n;i++){
				tmp[i]=a[i][1],tmp2[i]=a[i][2];
			}
			sort(tmp+1,tmp+1+n,greater<int>());
			sort(tmp2+1,tmp2+1+n,greater<int>());
			for(int i=1;i<=n/2;i++){
				res+=tmp[i]+tmp2[i];
			}
		}
		else dfs(1,0);
		cout<<res<<'\n';
	}
	return 0;
} 
