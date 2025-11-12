#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[110001][4];
int now[110001];
int cnt[4];
int res[110001];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		int n,sum=0;
		cin >>n;
		memset(res,128,sizeof res);
		memset(now,0,sizeof now);
		memset(w,0,sizeof w);
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin >>w[i][1]>>w[i][2]>>w[i][3];
			if(w[i][1]>=max(w[i][2],w[i][3]))now[i]=1;
			if(w[i][2]>=max(w[i][1],w[i][3]))now[i]=2;
			if(w[i][3]>=max(w[i][1],w[i][2])) now[i]=3;
			cnt[now[i]]++;
			sum+=w[i][now[i]];
		}
		int big=-1;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2)big=i;
		}
		if(big==-1){
			cout <<sum<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(now[i]!=big)continue;
			for(int j=1;j<=3;j++){
				if(j==big)continue;
				res[i]=max(res[i],-w[i][big]+w[i][j]);
			}
		}
		sort(res+1,res+n+1,cmp);
		for(int i=1;i<=cnt[big]-n/2;i++){
			sum+=res[i];
		}
		cout <<sum<<'\n';
	}
}
