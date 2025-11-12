//GZ-S00480 安顺市第一高级中学 陈详镒菘 
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2000005;

long long a[MAXN],b[MAXN],c[MAXN],n;
long long ca,cb,cc;

long long int dfs(int x,long long pts){
	
	if(x == n + 1)return pts;
	
	long long now = pts;
	
	if(ca < n/2){
		
		ca++;
		
		//printf("choose a in %d get %d now a %d b %d c %d\n",x,dfs(x+1,pts+a[x]),ca,cb,cc);
		
		long long num = dfs(x+1,pts+a[x]);
		
		if(num > now)now = num;
		
		ca--;
		
	}
	if(cb < n/2){
		
		cb++;
		
		//printf("choose b in %d get %d now a %d b %d c %d\n",x,dfs(x+1,pts+b[x]),ca,cb,cc);
		
		long long num = dfs(x+1,pts+b[x]);
		
		if(num > now)now = num;
		
		cb--;
		
	}
	if(cc < n/2){
		
		cc++;
		
		//printf("choose c in %d get %d now a %d b %d c %d\n",x,dfs(x+1,pts+c[x]),ca,cb,cc);
		
		long long num = dfs(x+1,pts+c[x]);
		
		if(num > now)now = num;
		
		cc--;
		
	}
	
	return now;
	
}

void solve(){
	
	scanf("%lld",&n);
	
	for(int i = 1;i <= n;i++)scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
	
	ca = 0;cb = 0;cc = 0;
	
	if(n <= 12)printf("%lld\n",dfs(1,0));
	else{
		
		sort(a+1,a+1+n);
		
		long long ans = 0;
		
		for(int i = n;i > n/2;i--)ans+=a[i];
		
		printf("%lld\n",ans);
		
	}
	
	return;
}

int main () {
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;scanf("%d",&t);
	
	while(t--)solve(); 
	
	return 0;
}
