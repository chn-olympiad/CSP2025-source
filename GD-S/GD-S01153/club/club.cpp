#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=201010;
ll T,n,a[N][4],pos[N][4],ans;
struct node{
	ll val,id;
	bool operator <(const node &a)const{
		return a.val<val;
	}
};
priority_queue<node>q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			pos[i][1]=1,pos[i][2]=2,pos[i][3]=3;
			for(int j=1;j<=3;j++){
				for(int k=1;k<=j;k++){
					if(a[i][pos[i][j]]>a[i][pos[i][k]])swap(pos[i][j],pos[i][k]);
				}
			}
			if(q[pos[i][1]].size()<n/2){
				q[pos[i][1]].push({a[i][pos[i][1]]-a[i][pos[i][2]],i});
				ans+=a[i][pos[i][1]];
			}
			else{
				if(a[i][pos[i][1]]-a[i][pos[i][2]]>q[pos[i][1]].top().val){
					node now=q[pos[i][1]].top();
					q[pos[i][1]].pop();
					ans=ans-now.val+a[i][pos[i][1]];
					q[pos[i][1]].push({a[i][pos[i][1]]-a[i][pos[i][2]],i});
					q[pos[now.id][2]].push({a[now.id][pos[now.id][2]]-a[now.id][pos[now.id][3]],now.id});
				}
				else{
					q[pos[i][2]].push({a[i][pos[i][2]]-a[i][pos[i][3]],i});
					ans+=a[i][pos[i][2]];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
