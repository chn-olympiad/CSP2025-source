#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
int a[200005][4];
int ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof a);
		ans=0;
		priority_queue<int> q1,q2,q3;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				q1.push(-(a[i][1]-max(a[i][2],a[i][3])));
				ans+=a[i][1];
			}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				q2.push(-(a[i][2]-max(a[i][1],a[i][3])));
				ans+=a[i][2];
			}else{
				q3.push(-(a[i][3]-max(a[i][1],a[i][2])));
				ans+=a[i][3];
			}
		}
		if(q1.size()>(n/2)){
			while(q1.size()>(n/2)){
				int j=-q1.top();
				q1.pop();
				ans-=j;
			}
		}else if(q2.size()>(n/2)){
			while(q2.size()>(n/2)){
				int j=-q2.top();
				q2.pop();
				ans-=j;
			}
		}else if(q3.size()>(n/2)){
			while(q3.size()>(n/2)){
				int j=-q3.top();
				q3.pop();
				ans-=j;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
