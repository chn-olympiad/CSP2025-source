#include<bits/stdc++.h>
using namespace std;
struct node1{
	int to_a,to_b,to_c;
};
struct node2{
	int val,id;
	bool operator<(const node2 another)const{
		return val>another.val;
	}
};
node1 stu[100010]; 
int dp[100010][5];
void solve1(int n){
	int mx=n/2;
	for(int i=1;i<=n;i++){
		cin>>stu[i].to_a>>stu[i].to_b>>stu[i].to_c;
	}
	priority_queue<node2>pq_a;
	priority_queue<node2>pq_b;	
	priority_queue<node2>pq_c;
	for(int i=1;i<=n;i++){
		if(stu[i].to_a>stu[i].to_b&&stu[i].to_a>stu[i].to_c){
			pq_a.push({stu[i].to_a,i});
			if(pq_a.size()>mx){
				node2 tmp=pq_a.top();
				int tmp_val=tmp.val,tmp_id=tmp.id;
				pq_a.pop();
				if(stu[tmp_id].to_b>stu[tmp_id].to_c){
					pq_b.push({stu[tmp_id].to_b,tmp_id});
					if(pq_b.size()>mx){
						pq_c.push({stu[tmp_id].to_c,tmp_id});
					}
				}
			}
		}
		else if(stu[i].to_b>stu[i].to_a&&stu[i].to_b>stu[i].to_c){
			pq_b.push({stu[i].to_b,i});
			if(pq_b.size()>mx){
				node2 tmp=pq_b.top();
				int tmp_val=tmp.val,tmp_id=tmp.id;
				pq_b.pop();
				if(stu[tmp_id].to_a>stu[tmp_id].to_c){
					pq_a.push({stu[tmp_id].to_a,tmp_id});
					if(pq_a.size()>mx){
						pq_c.push({stu[tmp_id].to_c,tmp_id});
					}
				}
			}
		}
		else{
			pq_c.push({stu[i].to_c,i});
			if(pq_c.size()>mx){
				node2 tmp=pq_c.top();
				int tmp_val=tmp.val,tmp_id=tmp.id;
				pq_c.pop();
				if(stu[tmp_id].to_a>stu[tmp_id].to_b){
					pq_a.push({stu[tmp_id].to_a,tmp_id});
					if(pq_a.size()>mx){
						pq_b.push({stu[tmp_id].to_b,tmp_id});
					}
				}
			}
		}
	}
	int ans=0;
	while(pq_a.size()){
		ans+=pq_a.top().val;
		pq_a.pop();
	}
	while(pq_b.size()){
		ans+=pq_b.top().val;
		pq_b.pop();
	}
	while(pq_c.size()){
		ans+=pq_c.top().val;
		pq_c.pop();
	}
	cout<<ans<<"\n";
}
int ans=0;
void dfs(int n,int id,int cnt_a,int cnt_b,int cnt_c,int sum){
	if(id>n){
		if(cnt_a<=n/2&&cnt_b<=n/2&&cnt_c<=n/2){
			ans=max(ans,sum);
		}
		return;
	}
	if(cnt_a+1<=n/2){
		dfs(n,id+1,cnt_a+1,cnt_b,cnt_c,sum+stu[id].to_a);
	}
	if(cnt_b+1<=n/2){
		dfs(n,id+1,cnt_a,cnt_b+1,cnt_c,sum+stu[id].to_b);
	}
	if(cnt_b+1<=n/2){
		dfs(n,id+1,cnt_a,cnt_b,cnt_c+1,sum+stu[id].to_c);
	}
} 
void solve2(int n){
	ans=0;
	int mx=n/2;
	for(int i=1;i<=n;i++){
		cin>>stu[i].to_a>>stu[i].to_b>>stu[i].to_c;
	}
	dfs(n,1,0,0,0,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<=15) solve2(n);
		else solve1(n);
	}
	return 0;
} 
