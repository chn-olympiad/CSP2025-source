#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+7;
struct node{
	int a,b,c;
};
node per[MAXN];
bool cmp(node a,node b){
	return a.a>b.a;
}
int n,ans=0;
void dfs(ll pos,ll a,ll b,ll c,ll val,ll hu){
	if(pos==n+1){
		if(val>ans)ans=val;
		return;
	}
	if(val+hu<ans)return;
	int tmp=max({per[pos].a,per[pos].b,per[pos].c});
	if(a<n/2){
		dfs(pos+1,a+1,b,c,val+per[pos].a,hu-tmp);
	}
	if(b<n/2){
		dfs(pos+1,a,b+1,c,val+per[pos].b,hu-tmp);
	}
	if(c<n/2){
		dfs(pos+1,a,b,c+1,val+per[pos].c,hu-tmp);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool s3=1;
	ll t,sum=0,hu;
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		s3=0;
		for(int i=1;i<=n;i++){
			cin>>per[i].a>>per[i].b>>per[i].c;
			if(per[i].c!=0)s3=0;
		}
		if(s3){
			for(int i=1;i<=n;i++)per[i].a-=per[i].b,sum+=per[i].b;
			sort(per+1,per+1+n,cmp);
			for(int i=1;i<=n/2;i++)sum+=per[i].a;
			cout<<sum<<'\n'; 
		}
		else{
			ans=hu=0;
			for(int i=1;i<=n;i++)hu+=max({per[i].a,per[i].b,per[i].c});
			dfs(1,0,0,0,0,hu);
			cout<<ans<<'\n';
		}
	}
}
