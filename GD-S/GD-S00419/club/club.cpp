#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int t,n,a[N],ans;
struct PT{int q[N],top;}p[5];
bool cmp(PT a,PT b){return a.top>b.top;}
signed main(){
//	freopen("club1.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		p[1].top=p[2].top=p[3].top=0;
		scanf("%lld",&n);
		for(int i=1,a,b,c;i<=n;i++){
			scanf("%lld%lld%lld",&a,&b,&c);
			if(a>=b&&a>=c) p[1].q[++p[1].top]=min(a-b,a-c),ans+=a;
			else if(b>=a&&b>=c) p[2].q[++p[2].top]=min(b-a,b-c),ans+=b;
			else if(c>=a&&c>=b) p[3].q[++p[3].top]=min(c-b,c-a),ans+=c;
		} 
		sort(p+1,p+3+1,cmp);
		for(int i=1;i<=p[1].top;i++) a[i]=p[1].q[i]; 
		sort(a+1,a+p[1].top+1);
		for(int i=1;i<=p[1].top-n/2;i++) ans-=a[i];
		cout<<ans<<endl;
	}
	return 0;
}
// fc D:\GD-S00419\club\club6.ans D:\GD-S00419\club\club.out
