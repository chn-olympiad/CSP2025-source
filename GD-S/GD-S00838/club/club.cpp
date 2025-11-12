#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+10;
struct st{
	int a,b,c;
};
st p[N];
bool cmpa(st x,st y){
	return (x.a-max(x.b,x.c))>(y.a-max(y.b,y.c));
}
bool cmpb(st x,st y){
	return (x.b-(max(x.a,x.c)))>(y.b-(max(y.a,y.c)));
}
bool cmpc(st x,st y){
	return (x.c-max(x.b,x.a))>(y.c-max(y.b,y.a));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		int n;
		cin>>n;
		int ma=0,mb=0,mc=0,md=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a==p[i].b&&p[i].a==p[i].c){
				md++;
				continue;
			}
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c){
				ma++;
				continue;
			}
			if(p[i].b>=p[i].a&&p[i].b>=p[i].c){
				mb++;
				continue;
			}
			if(p[i].c>=p[i].a&&p[i].c>=p[i].b){
				mc++;
				continue;
			}
		}
		if(ma>(n/2)){
			sort(p+1,p+1+n,cmpa);
			int i=1;
			for(;i<=n/2;i++){
				ans+=p[i].a;
			}
			for(;i<=n;i++){
				ans+=max(p[i].b,p[i].c);
			}
		}
		if(mb>(n/2)){
			sort(p+1,p+1+n,cmpb);
			int i=1;
			for(;i<=n/2;i++){
				ans+=p[i].b;
			}
			for(;i<=n;i++){
				ans+=max(p[i].a,p[i].c);
			}
		}
		if(mc>(n/2)){
			sort(p+1,p+1+n,cmpc);
			int i=1;
			for(;i<=n/2;i++){
				ans+=p[i].c;
			}
			for(;i<=n;i++){
				ans+=max(p[i].b,p[i].a);
			}
		}
		if(ma<=n/2&&mb<=n/2&&mc<=n/2){
			for(int i=1;i<=n;i++){
				ans+=max(p[i].a,max(p[i].b,p[i].c));
			}
		}
		cout<<ans<<endl;	
	}
	return 0;
} 
