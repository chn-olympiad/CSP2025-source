#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[100001][4],T;
struct node{
	int id,d,cha;
	bool operator <(const node b)const{
		return cha<b.cha;
	}
};
priority_queue<node> q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		for(int i=0;i<3;i++)while(!q[i].empty())q[i].pop();
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
		int ans=0;
		for(int i=1;i<=n;i++){
			int sum=0,p=0;
			for(int j=0;j<3;j++){
				int s;
				if(q[j].size()==n/2){
					node x=q[j].top();
					s=ans+x.cha+a[i][j];
				}
				else s=ans+a[i][j];
				if(s>sum)p=j,sum=s;
			}
			if(q[p].size()==n/2){
				node x=q[p].top();q[p].pop();
				ans=ans+x.cha+a[i][p];
				q[p].push({i,p,max(a[i][(p+1)%3],a[i][(p+2)%3])-a[i][p]});
			}
			else {
				ans=ans+a[i][p];
				q[p].push({i,p,max(a[i][(p+1)%3],a[i][(p+2)%3])-a[i][p]});
			}
		}
		cout<<ans<<'\n';
	}
}
/*

 */