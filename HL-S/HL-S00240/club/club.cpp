#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t;
int a[N];
int b[N];
int c[N];
int dp[N];
struct node{
	int a,b,c; 
}w[N];
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}
bool vis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool f1=0,f2=0;
		int d=n/2,ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			cin>>w[i].a>>w[i].b>>w[i].c;
			if(w[i].b!=0) f1=1;
			if(w[i].c!=0) f2=1,f1=1;
		}
		if(!f1){
			sort(w+1,w+n+1,cmp1); 
			for(int i=1;i<=d;i++){
				ans1+=w[i].a;
			}
			cout<<ans1<<'\n';
			continue;
		}else if(!f2){
			sort(w+1,w+n+1,cmp1); 
			for(int i=1;i<=d;i++){
				ans1+=w[i].a;
				vis[i]=1;
			}
			sort(w+1,w+n+1,cmp2);
			for(int i=1;i<=d;i++){
				if(!vis[i]) ans1+=w[i].b;
			}
			
			sort(w+1,w+n+1,cmp2); 
			for(int i=1;i<=d;i++){
				ans2+=w[i].b;
				vis[i]=1;
			}
			sort(w+1,w+n+1,cmp1);
			for(int i=1;i<=d;i++){
				if(!vis[i]) ans2+=w[i].a;
			}
			cout<<max(ans1,ans2)<<'\n';
			continue;
		}else{
			int cnta=0,cntb=0,cntc=0; 
			for(int i=1;i<=n;i++){ 
				int pa=0,pb=0,pc=0;
				if(cnta<d) pa=a[i-1]+w[i].a+b[i-1]+c[i-1];
				if(cntb<d) pb=a[i-1]+b[i-1]+w[i].b+c[i-1];
				if(cntc<d) pc=a[i-1]+b[i-1]+c[i-1]+w[i].c;
				int p=max(max(pa,pb),pc);
				if(p==pa){
					a[i]=dp[i-1]+w[i].a;
					cnta++;
				}else if(p==pb){
					b[i]=dp[i-1]+w[i].b;
					cntb++;
				}else if(p==pc){
					c[i]=dp[i-1]+w[i].c;
					cntc++;
				}
				dp[i]=p;
			}
			cout<<dp[n]<<'\n';
			}
		}
	return 0;
}
