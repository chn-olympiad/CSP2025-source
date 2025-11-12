//goodbye OI!------luogu uid 676569 at 18:22:43 2025/11/1
#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <queue> 
using namespace std;
int n;
struct person{
	int x,y,z;
	int mx;
	bool operator < (const person& p) const {
		return mx>p.mx;
	}
}a[100005];
namespace sub1{
	int dp[205][205][205];
	void sol(){
		for(int i=0;i<205;i++){
			for(int j=0;j<205;j++){
				for(int k=0;k<205;k++)
					dp[i][j][k]=0; 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i,n/2);k++){
					if(j+k>i)
						continue;
	//				cout<<i<<' '<<j<<' '<<k<<endl;
					if(j!=0)
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].x);
					if(k!=0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].y);
					}
					if(1<=(i-j-k)&&(i-j-k)<=n/2){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i].z);
					} 
				}
			}
		}
		int ans=0;
	//	cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=max(ans,dp[n][i][j]);
	//			cout<<i<<' '<<j<<' '<<dp[n][i][j]<<endl;
			}
		}
		cout<<ans<<endl;
	}
}
namespace sub2{
	struct pr_que{
		long long id,dis; 
		bool operator < (const pr_que& p) const {
			return dis>p.dis;
		}
	};
	long long res=0;
	priority_queue<pr_que> q1,q2,q3;
	void sol(){
		res=0;
		while(!q1.empty())
			q1.pop();
		while(!q2.empty())
			q2.pop();
		while(!q3.empty())
			q3.pop();
		for(int i=1;i<=n;i++){
			if(a[i].x==a[i].mx){
				q1.push({i,min(a[i].x-a[i].y,a[i].x-a[i].z)});
				res+=a[i].x;
				while(q1.size()>n/2){
					auto h=q1.top();
					int d=h.dis,id=h.id;
					if(d<0)
						continue;
					q1.pop();
					res-=d;
					if(a[id].x-a[id].y==d){
						q2.push({id,a[id].y-a[id].z});
					}
					else{
						q3.push({id,a[id].z-a[id].y});
					}
				} 
			}
			else if(a[i].y==a[i].mx){
				q2.push({i,min(a[i].y-a[i].z,a[i].y-a[i].x)});
				res+=a[i].y;
				while(q2.size()>n/2){
					auto h=q2.top();
					int d=h.dis,id=h.id;
					if(d<0)
						continue;
					q2.pop();
					res-=d;
					if(a[id].y-a[id].z==d){
						q3.push({id,a[id].y-a[id].x});
					}
					else{
						q1.push({id,a[id].y-a[id].z});
					}
				} 
			}
			else{
				q3.push({i,min(a[i].z-a[i].x,a[i].z-a[i].y)});
				res+=a[i].z;
				while(q3.size()>n/2){
					auto h=q3.top();
					int d=h.dis,id=h.id;
					if(d<0)
						continue; 
					q3.pop();
					res-=d;
					if(a[id].z-a[id].x==d){
						q1.push({id,a[id].z-a[id].y});
					}
					else{
						q2.push({id,a[id].z-a[id].x});
					}
				} 
			}
		}
		while(q1.size()>n/2){
			auto h=q1.top();
			int d=h.dis,id=h.id;
			if(d<0)
				continue;
			q1.pop();
			res-=d;
			if(a[id].x-a[id].y==d){
				q2.push({id,a[id].y-a[id].z});
			}
			else{
				q3.push({id,a[id].z-a[id].y});			
			}
		} 
		while(q2.size()>n/2){
			auto h=q2.top();
			int d=h.dis,id=h.id;
			if(d<0)
				continue;
			q2.pop();
			res-=d;
			if(a[id].y-a[id].z==d){
				q3.push({id,a[id].y-a[id].x});
			}
			else{
				q1.push({id,a[id].y-a[id].z});
			}
		}
		while(q3.size()>n/2){
			auto h=q3.top();
			int d=h.dis,id=h.id;
			if(d<0)
				continue; 
			q3.pop();
			res-=d;
			if(a[id].z-a[id].x==d){
				q1.push({id,a[id].z-a[id].y});
			}
			else{
				q2.push({id,a[id].z-a[id].x});
			}
		} 
		cout<<res<<endl;
	}
}
void sol(){
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y>>a[i].z,a[i].mx=max(a[i].x,max(a[i].y,a[i].z));
//	if(n<=200){
//		sub1::sol();
//		return ;
//	}
	sub2::sol();
} 
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>T;
	while(T--)
		sol(); 
	return 0;
}

