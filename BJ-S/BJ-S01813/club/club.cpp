#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}p[100005];
bool cmp(node x,node y){
	return x.a<y.a;
}
bool ab(node x,node y){
	return x.a-x.b<y.a-y.b;
}
bool ba(node x,node y){
	return x.b-x.a<y.b-y.a;
}
int t,n;
bool A=1,B=1;
int ans;
int x[100005];
void dfs(int x,int sum,int cnta,int cntb,int cntc){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	if(cnta<n/2) dfs(x+1,sum+p[x].a,cnta+1,cntb,cntc);
	if(cntb<n/2) dfs(x+1,sum+p[x].b,cnta,cntb+1,cntc);
	if(cntc<n/2) dfs(x+1,sum+p[x].c,cnta,cntb,cntc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		A=1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].b!=0 || p[i].c!=0) A=0;
			if(p[i].c!=0) B=0;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}
		if(A){
			sort(p+1,p+1+n,cmp);
			for(int i=n;i>n/2;i--){
				ans+=p[i].a;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(B){
			int acnt=0,bcnt=0,bdcnt=0;
			for(int i=1;i<=n;i++){
				if(p[i].a>p[i].b){
					x[i]=1;
					acnt++;
				}
				else if(p[i].a<p[i].b){
					x[i]=2;
					bcnt++;
				}
				else{
					x[i]=0;
					bdcnt++;
				}
			}
			if(abs(acnt-bcnt)==bdcnt || (bdcnt-abs(acnt-bcnt))%2==0){
				int ans=0;
				for(int i=1;i<=n;i++){
					if(x[i]==1){
						ans+=p[i].a;
						//cout<<p[i].a<<"\n";
					}
					else if(x[i]==2){
						ans+=p[i].b;
						//cout<<p[i].b<<"\n";
					}
					else{
						ans+=p[i].a;
						//cout<<p[i].a<<"\n";
					}
				}
				cout<<ans;
			}
		}
		
	}
	return 0;
}
