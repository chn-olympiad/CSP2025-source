#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N][3];
struct data{
	int x,y,z,mx,mxid;
};
data sp[N];
int a[N][3];
int b[N][3];
int cnt[3];
int ans=-1;
int n;
void dfs(int num,int idx){
	if(idx>n){
		ans=max(ans,num);
		return ;
	}
	for(int i=0;i<3;i++){
		if(cnt[i]<n/2){
		cnt[i]++;
		dfs(num+a[idx][i],idx+1);
		cnt[i]--;
		}
	}
}
bool cmp(data x,data y){
	return x.x>y.x;
}
bool cmp2(data x,data y){
	return x.mx>y.mx;
}
void solve(){
	int sp1=1,sp2=1;
	cin>>n;
	ans=-1;
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++){
		
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][1]!=a[i][2] or a[i][1] or a[i][2])sp1=0;
		if(a[i][2])sp2=0;
		sp[i].x=a[i][0],sp[i].y=a[i][1],sp[i].z=a[i][2];
	}
	if(sp1){
		sort(sp+1,sp+n+1,cmp);
		int res=0;
		for(int i=1;i<=n/2;i++){
			res+=sp[i].x;
		}
		cout<<res<<endl;
	}
	else if(sp2){
		for(int i=1;i<=n;i++){
			if(sp[i].x>sp[i].y){
				sp[i].mx=sp[i].x;
				sp[i].mxid=0;
			}
			else{
				sp[i].mx=sp[i].y;
				sp[i].mxid=1;
			}
		}
		sort(sp+1,sp+n+1,cmp2);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[sp[i].mxid]<n/2){
				ans+=sp[i].mx;
				cnt[sp[i].mxid]++;
			}
			else {
				if(sp[i].mxid==0){
					ans+=sp[i].y;
					cnt[1]++;
				}
				else {
					ans+=sp[i].x;
					cnt[0]++;
				}
			}
		}
		cout<<ans<<endl;
	}
	else {
	dfs(0,1);
	cout<<ans<<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	std::cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
