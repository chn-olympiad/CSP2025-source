#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
struct stu{
	long long v;
	int id;
	bool operator<(const stu &__StuB) const{
		return v<__StuB.v;
	}
};
int f[N][4],t,n;
long long dfs(int i,int ct1,int ct2,int ct3){
	if(i == n+1){
		return 0;
	}
	long long res = 0;
	if(ct1 < n/2){
		res = max(res,f[i][1]*1ll + dfs(i+1,ct1+1,ct2,ct3));
	}
	if(ct2 < n/2){
		res = max(res,f[i][2]*1ll + dfs(i+1,ct1,ct2+1,ct3));
	}
	if(ct3 < n/2){
		res = max(res,f[i][3]*1ll + dfs(i+1,ct1,ct2,ct3+1));
	}
	return res;
}
priority_queue<stu> af,bf,cf;
int qwq(long long x,long long y,long long z){
	if(x>y && x>z){
		return 0;
	}
	else if(y>x && y>z){
		return 1;
	}
	else if(z>x && z>y){
		return 2;
	}
	else{
		return -1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		while((!af.empty())) af.pop();
		while((!bf.empty())) bf.pop();
		while((!cf.empty())) cf.pop();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			f[i][0] = 0;
			scanf("%d %d %d",&f[i][1],&f[i][2],&f[i][3]);
		}
		if(n < 16){
			printf("%lld\n",dfs(1,0,0,0));
			continue;
		}
		for(int i=1;i<=n;i++){
			af.push(stu{f[i][1],i});
			bf.push(stu{f[i][2],i});
			cf.push(stu{f[i][3],i});
		}
		long long res;
		int ct1,ct2,ct3; res = ct1 = ct2 = ct3 = 0;
		while(ct1+ct2+ct3 < n){
			while((!af.empty()) && f[af.top().id][0] == 1) af.pop();
			while((!bf.empty()) && f[bf.top().id][0] == 1) bf.pop();
			while((!cf.empty()) && f[cf.top().id][0] == 1) cf.pop();
			long long x = af.top().v,y = bf.top().v,z = cf.top().v;
			int xid = af.top().id,yid = bf.top().id,zid = cf.top().id;
			if(qwq(x,y,z) == 0 && ct1 < n/2){
				res += x;
				ct1++;
				f[xid][0] = 1;
				continue;
			}
			else if(qwq(x,y,z) == 1 && ct2 < n/2){
				res += y;
				ct2++;
				f[yid][0] = 1;
				continue;
			}
			else{
				res += z;
				ct3++;
				f[zid][0] = 1;
				continue;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
