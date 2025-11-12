#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a,b,c;
	int mem,sum;
}s[300005];
bool vis[100005];
int b[130];
bool cmp(node x,node y){
	return x.mem!=y.mem?x.mem<y.mem:x.sum>y.sum;
}
signed main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(vis,false,sizeof vis);
		memset(b,0,sizeof b);
		int n;
		cin>>n;
		int b[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].sum=s[i].a+s[i].b+s[i].c;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c) s[i].mem=1,b[1]++;
			else if(s[i].b>=s[i].a&&s[i].b>=s[i].c) s[i].mem=2,b[2]++;
			else if(s[i].c>=s[i].b&&s[i].c>=s[i].a) s[i].mem=3,b[3]++;
		}
		sort(s+1,s+1+n,cmp);
		bool flaga=true,flagb=true,flagc=true;
		if(b[1]*2>n){
			flaga=false;
			for(int i=1;i<=n&&b[1]*2>n;i++){
				if(s[i].mem==1){
					if(s[i].b>s[i].c) b[1]--,s[i].mem=2,b[2]++;
					else b[1]--,s[i].mem=3,b[3]++;
				}
			}
			sort(s+1,s+1+n,cmp);
		}
		if(b[2]*2>n){
			flagb=false;
			for(int i=1;i<=n&&b[2]*2>n;i++){
				if(s[i].mem==2){
					if(s[i].a>s[i].c&&flaga==true) b[2]--,s[i].mem=1,b[1]++;
					else b[2]--,s[i].mem=3,b[3]++;
				}
			}
			sort(s+1,s+1+n,cmp);
		}
		if(b[3]*2>n){
			flagc=false;
			for(int i=1;i<=n&&b[2]*2>n;i++){
				if(s[i].mem==3){
					if(s[i].a>s[i].b&&flagb==false) b[3]--,s[i].mem=1,b[1]++;
					else b[3]--,s[i].mem=2,b[2]++;
				}
			}
			sort(s+1,s+1+n,cmp);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i].mem==1) ans+=s[i].a;
			if(s[i].mem==2) ans+=s[i].b;
			if(s[i].mem==3) ans+=s[i].c;
		}
		cout<<ans<<"\n";
	}	
	return 0;
}
