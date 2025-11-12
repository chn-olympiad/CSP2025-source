#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
	int a,b,c;
}p[100005];
ll n,ans,maxp;

void dfs(int who,int to,int sa,int sb,int sc,ll sum){
	if(who>n) ans=max(sum,ans);
	if(to==1){
		sa++;
		sum+=1ll*p[who].a;
		//cout<<who<<"->"<<to<<":"<<sum<<" "<<sa<<endl;
		if(sa<maxp) dfs(who+1,1,sa,sb,sc,sum); 
		if(sb<maxp) dfs(who+1,2,sa,sb,sc,sum); 
		if(sc<maxp) dfs(who+1,3,sa,sb,sc,sum); 
	}if(to==2){
		sb++;
		sum+=1ll*p[who].b;
		//cout<<who<<"->"<<to<<":"<<sum<<" "<<sb<<endl;
		if(sa<maxp) dfs(who+1,1,sa,sb,sc,sum); 
		if(sb<maxp) dfs(who+1,2,sa,sb,sc,sum); 
		if(sc<maxp) dfs(who+1,3,sa,sb,sc,sum); 
	}if(to==3){
		sc++;
		sum+=1ll*p[who].c;
		//cout<<who<<"->"<<to<<":"<<sum<<" "<<sc<<endl;
		if(sa<maxp) dfs(who+1,1,sa,sb,sc,sum); 
		if(sb<maxp) dfs(who+1,2,sa,sb,sc,sum); 
		if(sc<maxp) dfs(who+1,3,sa,sb,sc,sum); 
	}
}

void solve(){
	int _;
	cin>>_;
	while(_--){
		ans=-999;
		cin>>n;maxp=n/2;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		dfs(1,1,0,0,0,0);
		dfs(1,2,0,0,0,0);
		dfs(1,3,0,0,0,0);
		cout<<ans<<endl;
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
