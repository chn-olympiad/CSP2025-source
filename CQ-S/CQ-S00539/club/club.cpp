#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=3e5+5;
ll T,n,a[N][4],cnt[4],ans=0,res1,res2,res3;
priority_queue<ll> q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		res1=res2=res3=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		while(q1.size()) q1.pop();
		while(q2.size()) q2.pop();
		while(q3.size()) q3.pop();
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			ll x=a[i][1],y=a[i][2],z=a[i][3];
			//if(q1.size()) cout<<q1.top()<<endl;
			if(cnt[1]>=n/2&&q1.size()){
				x+=q1.top();res1++;
				//cout<<"p"<<x<<" "<<y<<" "<<z<<" "<<ans<<endl;
				if(x>=max(y,z)) ans+=x,q1.pop(),q1.push(max(y,z)-a[i][1]);
				else if(y>=max(x,z)) ans+=y,q2.push(max(x,z)-y),cnt[2]++;
				else ans+=z,q3.push(max(x,y)-z),cnt[3]++;
			}
			else if(cnt[2]>=n/2&&q2.size()){
				y+=q2.top();res2++;
				if(x>=max(y,z)) ans+=x,q1.push(max(y,z)-x),cnt[1]++;
				else if(y>=max(x,z)) ans+=y,q2.pop(),q2.push(max(x,z)-a[i][2]);
				else ans+=z,q3.push(max(x,y)-z),cnt[3]++;
			}
			else if(cnt[3]>=n/2&&q3.size()){
				z+=q3.top();res3++;
				if(x>=max(y,z)) ans+=x,q1.push(max(y,z)-x),cnt[1]++;
				else if(y>=max(x,z)) ans+=y,q2.push(max(x,z)-y),cnt[2]++;
				else ans+=z,q3.pop(),q3.push(max(x,y)-a[i][3]);
			}
			else{
				if(x>=max(y,z)) ans+=x,q1.push(max(y,z)-x),cnt[1]++;
				else if(y>=max(x,z)) ans+=y,q2.push(max(x,z)-y),cnt[2]++;
				else ans+=z,q3.push(max(x,y)-z),cnt[3]++;				
			}
			//cout<<"P"<<" "<<a[i][1]<<" "<<x<<" "<<y-x<<" "<<z-x<<"  "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<" "<<ans<<endl; 
		}
		cout<<ans<<endl;
	}
	return 0;
}
//dp[i][j][k]=dp[i-1][j][k]
