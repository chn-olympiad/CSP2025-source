#include<bits/stdc++.h>
using namespace std;
struct ap{
	int now,to,val;
	bool operator <(const ap&other)const{
		return other.val<val;
	}
};
int n,t,a[5],ans;
priority_queue<ap> que;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		a[1]=a[2]=a[3]=ans=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				a[1]++;
				que.push({1,2,x-y});
				que.push({1,3,x-z});
				ans+=x;
				continue;
			}
			else if(y>=x&&y>=z){
				a[2]++;
				que.push({2,1,y-x});
				que.push({2,3,y-z});
				ans+=y;
				continue;
			}
			else{
				a[3]++;
				que.push({3,2,z-y});
				que.push({3,1,z-x});
				ans+=z;
			}
		}
		while(!que.empty()){
			ap p=que.top();
			que.pop();
			if(a[p.now]>(n/2)){
				ans-=p.val;
				a[p.now]--;
				a[p.to]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
