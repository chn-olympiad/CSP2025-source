#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int T,n;
ll a[N][5];
ll ans = -1ll;
int cnt[5];
void dfs(int x,ll sum){
	if(x > n){
		ans = max(ans,sum);
		return;
	}
	if(cnt[1] < n/2)++cnt[1],dfs(x+1,sum+a[x][1]),--cnt[1];
	if(cnt[2] < n/2)++cnt[2],dfs(x+1,sum+a[x][2]),--cnt[2];
	if(cnt[3] < n/2)++cnt[3],dfs(x+1,sum+a[x][3]),--cnt[3];
}
typedef pair<ll,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q1,q2,q3;
ll sum = 0ll;
void s1(); void s2(); void s3();
void s1(){
	while(cnt[1] > n/2){
		int x = q1.top().second;
		ll d = q1.top().first;
		if(d == (ll)(1e18))break;
		q1.pop(); --cnt[1];
		sum -= d;
		if(d == a[x][1]-a[x][2]){
			if(a[x][2] > a[x][3])q2.push(make_pair(a[x][2]-a[x][3],x)); // 1,2,3
			else q2.push(make_pair(1e18,x)); // 3,1,2
		}else{ // 1->3
			if(a[x][3] > a[x][2])q3.push(make_pair(a[x][3]-a[x][2],x)); // 1,3,2
			else q3.push(make_pair(1e18,x)); // 2,1,3
		}
	}
	if(cnt[2] > n/2)s2();
	if(cnt[3] > n/2)s3();
}
void s2(){
	while(cnt[2] > n/2){
		int x = q2.top().second;
		ll d = q2.top().first;
		if(d == (ll)(1e18))break;
		q2.pop(); -- cnt[2];
		sum -= d;
		if(d == a[x][2]-a[x][1]){
			if(a[x][1] > a[x][3])q1.push(make_pair(a[x][1]-a[x][3],x)); //2,1,3
			else q1.push(make_pair(1e18,x));  // 3,2,1
		}else{ // 
			if(a[x][3] > a[x][1])q3.push(make_pair(a[x][3]-a[x][1],x)); // 2,3,1
			else q3.push(make_pair(1e18,x)); // 1,2,3
		}
	}
	if(cnt[1] > n/2)s1();
	if(cnt[3] > n/2)s3();
}
void s3(){
	while(cnt[3] > n/2){
		int x = q3.top().second;
		ll d = q3.top().first;
		if(d == (ll)(1e18))break;
		q3.pop(); -- cnt[3];
		sum -= d;
		if(d == a[x][3]-a[x][1]){
			if(a[x][1] > a[x][2])q1.push(make_pair(a[x][1]-a[x][2],x)); //3,1,2
			else q1.push(make_pair(1e18,x));  // 2,3,1
		}else{ // 
			if(a[x][2] > a[x][1])q2.push(make_pair(a[x][2]-a[x][1],x)); // 3,2,1
			else q2.push(make_pair(1e18,x)); // 1,3,2
		}
	}
	if(cnt[1] > n/2)s1();
	if(cnt[2] > n/2)s2();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans = -1ll;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j)scanf("%lld",&a[i][j]);
		}
		if(n <= 10){
			for(int i=1;i<=3;++i)cnt[i] = 0;
			dfs(1,0ll);
			printf("%lld\n",ans);
		}else{
			sum = 0;
			while(!q1.empty())q1.pop();
			while(!q2.empty())q2.pop();
			while(!q3.empty())q3.pop();
			for(int i=1;i<=3;++i)cnt[i] = 0;
			for(int i=1;i<=n;++i){
				if(a[i][1] > a[i][2]){
					if(a[i][1] > a[i][3]){ 
						q1.push(make_pair(min(a[i][1]-a[i][2],a[i][1]-a[i][3]),i));
						++cnt[1];
						sum += a[i][1];
					}else{ // 3,1,2
						q3.push(make_pair(a[i][3]-a[i][1],i));
						++cnt[3];
						sum += a[i][3];
					}
				}else{
					if(a[i][2] > a[i][3]){ 
						q2.push(make_pair(min(a[i][2]-a[i][1],a[i][2]-a[i][3]),i));
						++cnt[2];
						sum += a[i][2];
					}else{ // 3,2,1
						q3.push(make_pair(a[i][3]-a[i][2],i));
						sum += a[i][3];
						++cnt[3];
					}
				}
			}
			//cout<<sum<<endl;
			if(cnt[1] > n/2)s1();
			if(cnt[2] > n/2)s2(); 
			if(cnt[3] > n/2)s3();
			printf("%lld\n",sum);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
