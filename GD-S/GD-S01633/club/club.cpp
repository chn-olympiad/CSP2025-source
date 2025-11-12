#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,ans,cnt[4];

struct link{
	int pos,val;
	friend bool operator < (link u,link v){
		return u.val>v.val;
	}
} a[N][4];

priority_queue<link> q[4];

void small_sort(link &u,link &v,link &w){
	if(v<u) swap(u,v);
	if(w<v) swap(w,v);
	if(v<u) swap(u,v);
}

void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j].val;
			a[i][j].pos=j;
		}
		small_sort(a[i][1],a[i][2],a[i][3]);
	}
	cnt[1]=cnt[2]=cnt[3]=0;
	ans=0;
	for(int i=1;i<=3;i++)
		while(!q[i].empty())
			q[i].pop();
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--){
		
		init();
		
		for(int i=1;i<=n;i++){
			
			int p=a[i][1].pos,v=a[i][1].val,p2=a[i][2].pos,v2=a[i][2].val;
			if(cnt[p]<n/2){
				
				ans+=v;
				q[p].push({p2,v-v2});
				cnt[p]++;
				
			}
			else{
				
				link tmp=q[p].top();
				if(tmp.val<v-v2){
					q[p].pop();
					q[p].push({p2,v-v2});
					q[tmp.pos].push({tmp.pos,2147483647});
					cnt[tmp.pos]++;
					ans+=v-tmp.val;
				}
				else{
					ans+=v2;
					q[p2].push({p2,2147483647});
					cnt[p2]++;
				}
				
			}
			
		}
		
		cout<<ans<<"\n";
		
	}
	
	return 0;
	
} 

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

//CCF别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂
