#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=2e4+5;
int T,n,a[N][3],ans;
int i1[N],i2[N];
struct _{
	int u,id,cnt;
	bool operator>(const _& a)const{return u>a.u;}
};
priority_queue<_,vector<_>,greater<_> > q[3];
void solve(){
	if(q[1].size()>=q[2].size()&&q[1].size()>=q[3].size()){
		while(q[1].size()>n/2){
			int u=q[1].top().u;
			q[1].pop();ans-=u;
		}
	}else if(q[2].size()>=q[1].size()&&q[2].size()>=q[3].size()){
		while(q[2].size()>n/2){
			int u=q[2].top().u;
			q[2].pop();ans-=u;
		}
	}else{
		while(q[3].size()>n/2){
			int u=q[3].top().u;
			q[3].pop();ans-=u;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
		memset(i1,0,sizeof i1);
		memset(i2,0,sizeof i2);
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				i1[i]=1;
				if(a[i][2]>=a[i][3]) i2[i]=2;
				else i2[i]=3;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				i1[i]=2;
				if(a[i][1]>=a[i][3]) i2[i]=1;
				else i2[i]=3;
			}else{
				i1[i]=3;
				if(a[i][1]>=a[i][2]) i2[i]=1;
				else i2[i]=2;
			}
			q[i1[i]].push((_){a[i][i1[i]]-a[i][i2[i]],i,1});
			ans+=a[i][i1[i]];
		}
		solve();
	}
	return 0;
} 
