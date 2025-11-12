#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
struct node{
	int a,b,c;
}x[N];
ll n,ma[N],dp[N][N],maxx;
bool cmp(node p,node y){
	return max(p.a,max(p.b,p.c))>max(y.a,max(y.b,y.c));
}
void dfs(ll a,ll b,ll c,ll d,ll ans){
	//printf("%d %d %d %d %d\n",a,b,c,d,ans);
	if(b>n/2 || c>n/2 || d>n/2)return;
	if(a==n+1){
		maxx=max(ans,maxx);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			dfs(a+1,b+1,c,d,ans+x[a].a);
		}else if(i==2){
			dfs(a+1,b,c+1,d,ans+x[a].b);
		}else{
			dfs(a+1,b,c,d+1,ans+x[a].c);
		}
	}
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		bool f1=0,f2=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].b!=0)f1=1;
			if(x[i].c!=0)f2=1;
		}
		ll ans=0;
		sort(x+1,x+1+n,cmp);
		if(!f1 && !f2){
			for(int i=1;i<=n/2;i++){
				ans+=x[i].a;
			}
			cout<<ans<<endl;
			return 0;
		}else if(!f2){
			int aa=0,bb=0;
			for(int i=1;i<=n;i++){
				if(x[i].a>x[i].b){
					if(aa<n/2){
						aa++;
						ans+=x[i].a;
					}else{
						bb++;
						ans+=x[i].b;
					}
				}else{
					if(bb<n/2){
						bb++;
						ans+=x[i].b;
					}else{
						aa++;
						ans+=x[i].a;
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		dfs(1,0,0,0,0);
		cout<<maxx<<endl;
		memset(x,0,sizeof(x));
		maxx=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
4
1 2 0 
2 3 0 
3 4 0 
4 5 0 



*/
