#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--&&cin>>n){
		ans=0;
		priority_queue<long long,vector<long long>,greater<long long> >q[4];
		for(long long i=1,x,y,z;i<=n&&cin>>x>>y>>z;i++){
			ans+=max(x,max(y,z));
			if(x>y&&x>z)q[1].push(x-max(y,z));
			else if(y>x&&y>z)q[2].push(y-max(x,z));
			else q[3].push(z-max(x,y));
		}for(int i=q[1].size();i>n/2;i--){
			ans-=q[1].top();
			q[1].pop(); 
		}for(int i=q[2].size();i>n/2;i--){
			ans-=q[2].top();
			q[2].pop(); 
		}for(int i=q[3].size();i>n/2;i--){
			ans-=q[3].top();
			q[3].pop(); 
		}cout<<ans<<'\n';
	}return 0;
} 
