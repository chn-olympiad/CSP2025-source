#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
vector<int>z[4];
vector<pair<int,int>>q;
bitset<100005>vis;
int p[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		z[1].clear(),z[2].clear(),z[3].clear(),q.clear(),vis=0,ans=0;
		int len=n/2;
		for(int i=1;i<=n;i++){
			cin>>p[i][1]>>p[i][2]>>p[i][3];
			ans+=max({p[i][1],p[i][2],p[i][3]});
			if(p[i][1]>=p[i][2]&&p[i][1]>=p[i][3])z[1].push_back(i);
			else if(p[i][2]>=p[i][1]&&p[i][2]>=p[i][3])z[2].push_back(i);
			else z[3].push_back(i);
		}
		if(z[1].size()<=len&&z[2].size()<=len&&z[3].size()<=len){
			cout<<ans<<'\n';
			continue;
		}
		int cnt;
		if(z[1].size()>len){
			cnt=z[1].size()-len;
			for(int i:z[1]){
				q.push_back({p[i][1]-p[i][2],i});
				q.push_back({p[i][1]-p[i][3],i});
			}
		}if(z[2].size()>len){
			cnt=z[2].size()-len;
			for(int i:z[2]){
				q.push_back({p[i][2]-p[i][1],i});
				q.push_back({p[i][2]-p[i][3],i});
			}
		}if(z[3].size()>len){
			cnt=z[3].size()-len;
			for(int i:z[3]){
				q.push_back({p[i][3]-p[i][1],i});
				q.push_back({p[i][3]-p[i][2],i});
			}
		}
		sort(q.begin(),q.end());
		for(pair<int,int> i:q){
			int a=i.first,b=i.second;
			if(!vis[b]){
				cnt--;
				ans-=a;
				vis[b]=1;
			}if(cnt==0)break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

