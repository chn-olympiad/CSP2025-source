#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum[5],now[100010],ans,cnt[5],s[100010][5];
struct Node{
	int id,i,w;
	bool operator < (const Node &tmp)const{
		return w<tmp.w;
	}
};
priority_queue<Node>pq;
void work(){
	while(pq.empty()==false){
		int cur=pq.top().i,to=pq.top().id,w=pq.top().w;
		pq.pop();
		if((cnt[now[cur]]>n/2 or (cnt[now[cur]]<=n/2 and w>0)) and cnt[to]<n/2){
			sum[to]+=s[cur][to];
			sum[now[cur]]-=s[cur][now[cur]];
			cnt[now[cur]]--;
			cnt[to]++;
			now[cur]=to;
			if(to==1){
				pq.push(Node{2,cur,s[cur][2]-s[cur][1]});
				pq.push(Node{3,cur,s[cur][3]-s[cur][1]});
			}else if(to==2){
				pq.push(Node{1,cur,s[cur][1]-s[cur][2]});
				pq.push(Node{3,cur,s[cur][3]-s[cur][2]});
			}else{
				pq.push(Node{1,cur,s[cur][1]-s[cur][3]});
				pq.push(Node{2,cur,s[cur][2]-s[cur][3]});
			}
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
		}
		cnt[1]=cnt[2]=cnt[3]=sum[1]=sum[2]=sum[3]=0;
		for(int i=1;i<=n;i++){
			now[i]=1;
			sum[1]+=s[i][1],cnt[1]++;
			pq.push(Node{2,i,s[i][2]-s[i][1]});
			pq.push(Node{3,i,s[i][3]-s[i][1]});
		}
		work();
		ans=max(ans,sum[1]+sum[2]+sum[3]);
		cnt[1]=cnt[2]=cnt[3]=sum[1]=sum[2]=sum[3]=0;
		for(int i=1;i<=n;i++){
			now[i]=2;
			sum[2]+=s[i][2],cnt[2]++;
			pq.push(Node{1,i,s[i][1]-s[i][2]});
			pq.push(Node{3,i,s[i][3]-s[i][2]});
		}
		work();
		ans=max(ans,sum[1]+sum[2]+sum[3]);
		cnt[1]=cnt[2]=cnt[3]=sum[1]=sum[2]=sum[3]=0;
		for(int i=1;i<=n;i++){
			now[i]=3;
			sum[3]+=s[i][3],cnt[3]++;
			pq.push(Node{2,i,s[i][2]-s[i][3]});
			pq.push(Node{1,i,s[i][1]-s[i][3]});
		}
		work();
		ans=max(ans,sum[1]+sum[2]+sum[3]);
		cout<<ans<<"\n";
	}
	return 0;
}
