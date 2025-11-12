#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+10;
long long ai,bi,ci;
struct ns{
	long long idx;
	long long like;
};
priority_queue<long long> q; 
ns a[N],b[N],c[N]; 
long long f[N][4];
bool cmp(ns x,ns y){
	return x.like<y.like;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		ai=bi=ci=0;
		long long n;
		cin>>n;
		long long mx=n/2;
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&f[i][1],&f[i][2],&f[i][3]);
			if(f[i][1]>=f[i][2]&&f[i][1]>=f[i][3]) {
				a[++ai].like=f[i][1];
				a[ai].idx=i;
			}
			else if(f[i][2]>=f[i][1]&&f[i][2]>=f[i][3]){
				b[++bi].like=f[i][2];
				b[bi].idx=i;
			}
			else {
				c[++ci].like=f[i][3];
				c[ci].idx=i;
			}
		}
		long long sum=0;
		for(long long i=1;i<=ai;i++) sum+=a[i].like;
		for(long long i=1;i<=bi;i++) sum+=b[i].like;
		for(long long i=1;i<=ci;i++) sum+=c[i].like;
		if(ai>mx){
			for(long long i=1;i<=ai;i++){
				long long cge=0;
				cge-=a[i].like;
				if(bi+1<=mx&&ci+1<=mx) q.push(max(cge+f[a[i].idx][2],cge+f[a[i].idx][3]));
				else if(bi+1>mx) q.push(cge+f[a[i].idx][3]);
				else q.push(cge+f[a[i].idx][2]);
			}
			long long x=ai-mx;
			while(x--) {
				sum+=q.top();
				q.pop();
			}
			while(!q.empty()) q.pop();
		}
		else if(bi>mx){
			for(long long i=1;i<=bi;i++){
				long long cge=0;
				cge-=b[i].like;
				if(ai+1<=mx&&ci+1<=mx) q.push(max(cge+f[b[i].idx][1],cge+f[b[i].idx][3]));
				else if(ai+1>mx) q.push(cge+f[b[i].idx][3]);
				else q.push(cge+f[b[i].idx][1]);
			}
			long long x=bi-mx;
			while(x--) {
				sum+=q.top();
				q.pop();
			}
			while(!q.empty()) q.pop();
		} 
		else if(ci>mx){
			for(long long i=1;i<=ci;i++){
				long long cge=0;
				cge-=c[i].like;
				if(ai+1<=mx&&bi+1<=mx) q.push(max(cge+f[c[i].idx][2],cge+f[c[i].idx][1]));
				else if(bi+1>mx) q.push(cge+f[c[i].idx][1]);
				else q.push(cge+f[c[i].idx][2]);
			}
			long long x=ci-mx;
			while(x--) {
				sum+=q.top();
				q.pop();
			}
			while(!q.empty()) q.pop();
		}
		printf("%lld\n",sum);
	}//147325
	return 0;
}
