#include<bits/stdc++.h>
#include<queue>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,t,ans,q;
ll d[N][4],per[4],cut[N],w[N];
bool flag1=true,flag2=true;
void dfs(ll p,ll val){
	q++;
	if(q>=6000000)
	if(p>n){
		ans=max(ans,val);
		return;
	} 
	if(val+cut[p]<ans) return;
	if(per[1]<n/2){
		per[1]++;
		dfs(p+1,d[p][1]+val);	
		per[1]--;
	}
	if(per[2]<n/2){
		per[2]++;
		dfs(p+1,d[p][2]+val);	
		per[2]--;
	}
	if(per[3]<n/2&&flag1==false){
		per[3]++;
		dfs(p+1,d[p][3]+val);
		per[3]--;
	}
	return;
}
bool sw(int x,int y) {
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		flag1=true;
		flag2=true;
		ans=0;
		q=0;
		for(int i=1;i<=3;i++) per[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i][1],&d[i][2],&d[i][3]);
			if(flag1&&d[i][3]!=0) flag1=false;
			if(d[i][3]!=0||d[i][2]!=0) flag2=false;
		} 
		if(flag2){
			for(int i=1;i<=n;i++) w[i]=d[i][1];
			sort(w+1,w+1+n,sw);
			for(int i=1;i<=n/2;i++) ans+=w[i];
			cout<<ans<<endl;
			continue;
		}
		for(int i=n;i>=1;i--){
			cut[i]=cut[i+1]+max(d[i][1],max(d[i][2],d[i][3]));
		}
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
} 
