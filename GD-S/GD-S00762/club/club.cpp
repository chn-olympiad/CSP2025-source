#include<bits/stdc++.h>
using namespace std;

long long rd(){
	long long res=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0')res=res*10+c-'0',c=getchar();
	return res;
}
void wt(long long x){
	if(x>9)wt(x/10);
	putchar(x%10+'0');
}
long long ans,t,n,a[3][100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	scanf("%lld",&t);
	t=rd();
	while(t--){
		priority_queue<long long> q[3];
		ans=0;
		n=rd();
//		scanf("%lld",&n);
		for(int i=1;i<=n;++i){
			a[0][i]=rd(),a[1][i]=rd(),a[2][i]=rd();
//			scanf("%lld%lld%lld",&a[0][i],&a[1][i],&a[2][i]);
			if(a[0][i]>=a[1][i]&&a[0][i]>=a[2][i]){
				ans+=a[0][i];
				q[0].push(max(a[1][i],a[2][i])-a[0][i]);
			}else if(a[1][i]>=a[0][i]&&a[1][i]>=a[2][i]){
				ans+=a[1][i];
				q[1].push(max(a[0][i],a[2][i])-a[1][i]);
			}else{
				ans+=a[2][i];
				q[2].push(max(a[0][i],a[1][i])-a[2][i]);
			}
		}
		while(q[0].size()>(n/2)){
			ans+=q[0].top();
			q[0].pop();
		}
		while(q[1].size()>(n/2)){
			ans+=q[1].top();
			q[1].pop();
		}
		while(q[2].size()>(n/2)){
			ans+=q[2].top();
			q[2].pop();
		}
		wt(ans);
		putchar('\n');
	}
	return 0;
}

