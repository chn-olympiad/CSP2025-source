//code by ZXZMC
//完辣 20pts 
//总分最多45pts，甚至没法过线。。。 
//T1 AK ME
#include<bits/stdc++.h>
#define csp using
#define ak namespace
#define me std;
csp ak me
using namespace std;
const int N=1e5+10;
struct node{
	int id,val;
	bool operator <(const node &x)const{
		return val>x.val;
	}
};
int n,ans;
node a[N][5];
int c[N][5];
int cnt[5];
bool flag[N];
int b[N];
bool cmp1(int x,int y){
	return a[x][1].val>a[y][1].val;
}
bool cmp2(int x,int y){
	return a[x][2].val>a[y][2].val;
}
bool cmp3(int x,int y){
	return a[x][3].val>a[y][3].val;
}
void dfs(int x,int sum){
	if(x>n){
		ans=max(ans,sum); return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]>=n/2) continue;
		cnt[i]++;
		dfs(x+1,sum+c[x][i]);
		cnt[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n; ans=0;
		memset(cnt,0,sizeof cnt);
		memset(flag,0,sizeof flag);
		if(n<=10){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=3;j++) cin>>c[i][j];
			dfs(1,0);
			
			cout<<ans<<endl;
			continue;
		} 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].val;
				a[i][j].id=j;
			}
			b[i]=i;
			sort(a[i]+1,a[i]+4);
		}
		sort(b+1,b+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(flag[b[i]]) continue;
			if(cnt[a[b[i]][1].id]>=n/2) continue;
			cnt[a[b[i]][1].id]++,ans+=a[b[i]][1].val,flag[b[i]]=1;
		}
		sort(b+1,b+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(flag[b[i]]) continue;
			if(cnt[a[b[i]][2].id]>=n/2) continue;
			cnt[a[b[i]][2].id]++,ans+=a[b[i]][2].val,flag[b[i]]=1;
		}
		sort(b+1,b+1+n,cmp3);
		for(int i=1;i<=n;i++){
			if(flag[b[i]]) continue;
			if(cnt[a[b[i]][3].id]>=n/2) continue;
			cnt[a[b[i]][3].id]++,ans+=a[b[i]][3].val,flag[b[i]]=1;
		}
		cout<<ans<<endl; 
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
