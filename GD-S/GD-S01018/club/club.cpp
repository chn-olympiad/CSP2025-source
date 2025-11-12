#include<bits/stdc++.h>
#define ll long long
#define pll pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+8;
int n;
int cnt[3],a[N][3],v[3];
int id[N];
priority_queue<pll> q[6];
void chan(int i,int x){
	id[i]=x;
	if(x==0){
		q[0].push({a[i][1]-a[i][0],i});
		q[1].push({a[i][2]-a[i][0],i});
	}
	if(x==1){
		q[2].push({a[i][0]-a[i][1],i});
		q[3].push({a[i][2]-a[i][1],i});
	}
	if(x==2){
		q[4].push({a[i][0]-a[i][2],i});
		q[5].push({a[i][1]-a[i][2],i});
	}
}
void work(){
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	while(!q[3].empty()) q[3].pop();
	while(!q[4].empty()) q[4].pop();
	while(!q[5].empty()) q[5].pop();
	int ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		while(!q[0].empty()&&id[q[0].top().se]!=0) q[0].pop();
		while(!q[1].empty()&&id[q[1].top().se]!=0) q[1].pop();
		while(!q[2].empty()&&id[q[2].top().se]!=1) q[2].pop();
		while(!q[3].empty()&&id[q[3].top().se]!=1) q[3].pop();
		while(!q[4].empty()&&id[q[4].top().se]!=2) q[4].pop();
		while(!q[5].empty()&&id[q[5].top().se]!=2) q[5].pop();
		if(cnt[0]==n/2) v[0]=a[i][0]+max(q[0].top().fi,q[1].top().fi);
		else v[0]=a[i][0];
		
		if(cnt[1]==n/2) v[1]=a[i][1]+max(q[2].top().fi,q[3].top().fi);
		else v[1]=a[i][1];
		
		if(cnt[2]==n/2) v[2]=a[i][2]+max(q[4].top().fi,q[5].top().fi);
		else v[2]=a[i][2];
		
		if(v[0]>=v[1]&&v[0]>=v[2]){
			ans=ans+v[0];
			chan(i,0);
			if(cnt[0]==n/2){
				if(q[0].top().fi>q[1].top().fi)
					chan(q[0].top().se,1);
				else chan(q[1].top().se,2);
				cnt[0]--;
			}
			cnt[0]++;
		}
		else if(v[1]>=v[0]&&v[1]>=v[2]){
			ans=ans+v[1];
			chan(i,1);
			if(cnt[1]==n/2){
				if(q[2].top().fi>q[3].top().fi)
					chan(q[2].top().se,0);
				else chan(q[3].top().se,2);
				cnt[1]--;
			}
			cnt[1]++;
		}
		else{
			ans=ans+v[2];
			chan(i,2);
			if(cnt[2]==n/2){
				if(q[4].top().fi>q[5].top().fi)
					chan(q[4].top().se,0);
				else chan(q[5].top().se,1);
				cnt[2]--;
			}
			cnt[2]++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--){
		work();
	}
	return 0;
}
