#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
	int w,f,t;
};

bool operator <(const Node a,const Node b) {return a.w>b.w;} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T; cin>>T;
	while(T--) {
		int n; cin>>n;
		priority_queue<Node>q;
		ll ans=0;
		int c1=0,c2=0,c3=0,cnt=0;
		for(int i=0;i<n;i++) {
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			if(a3==0) cnt++;
			if(a1>=a2&&a1>=a3) {
				ans+=a1;c1++;
				q.push({a1-a2,1,2}),q.push({a1-a3,1,3});
			}
			else if(a2>=a1&&a2>=a3) {
				ans+=a2;c2++;
				q.push({a2-a1,2,1}),q.push({a2-a3,2,3});
			}
			else {
				ans+=a3;c3++;
				q.push({a3-a1,3,1}),q.push({a3-a2,3,2});
			}
		}
		//cout<<c1<<' '<<c2<<' '<<c3<<endl;
		bool ban=0; 
		if(cnt==n) ban=1;
		while(!q.empty()) {
			if(c1<=n/2&&c2<=n/2&&c3<=n/2) break;
			Node u=q.top();
			q.pop();
			if(ban&&u.t==3) continue;
			if(u.t==1&&c1>n/2) continue;
			if(u.t==2&&c2>n/2) continue;
			if(u.t==3&&c3>n/2) continue;
			if(u.f==1&&c1<=n/2) continue;
			if(u.f==2&&c2<=n/2) continue;
			if(u.f==3&&c3<=n/2) continue;
			//cout<<u.f<<' '<<u.t<<' '<<u.w<<endl;
			ans-=u.w;
			if(u.f==1) c1--;
			else if(u.f==2) c2--;
			else c3--;
			if(u.t==1) c1++;
			else if(u.t==2) c2++;
			else c3++;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
} 
