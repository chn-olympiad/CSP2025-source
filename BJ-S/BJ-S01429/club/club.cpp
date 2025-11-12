#include<bits/stdc++.h>
using namespace std;
int t;
int st[100001],a[100001][3],cnt[3],m[100001][2];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxx=max(a[i][0],max(a[i][1],a[i][2]) );
			ans+=maxx;
			m[i][0]=maxx;
			if(a[i][0]==maxx){
				m[i][1]=max(a[i][1],a[i][2]);
				st[i]=0;
				cnt[0]++;
			}
			else if(a[i][1]==maxx){
				m[i][1]=max(a[i][0],a[i][2]);
				st[i]=1;
				cnt[1]++;
			}
			else if(a[i][2]==maxx){
				m[i][1]=max(a[i][0],a[i][1]);
				st[i]=2;
				cnt[2]++;
			}
		}
		int lim=n/2;
		if(cnt[0]<=lim&&cnt[1]<=lim&&cnt[2]<=lim){
			cout<<ans<<endl;
		}
		else {
			priority_queue<int> q;
			int o;
			if(cnt[0]>lim)o=0;
			if(cnt[1]>lim)o=1;
			if(cnt[2]>lim)o=2;
			for(int i=1;i<=n;i++){
				if(st[i]==o){
					q.push(m[i][1]-m[i][0]);
				}
			}
			while(q.size()>lim){
				ans+=q.top();
				q.pop();
			}
			cout<<ans<<endl;
		}
		memset(st,0,sizeof st);
		memset(a,0,sizeof a);
		memset(cnt,0,sizeof cnt);
		memset(m,0,sizeof m);
	}
}
