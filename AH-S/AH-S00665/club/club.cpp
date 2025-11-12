#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5];
priority_queue<long long> o,p,q; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		while(!o.empty()) o.pop();
		while(!p.empty()) p.pop();
		while(!q.empty()) q.pop();
		cin>>n;
		long long ans=0;
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=3;j++) cin>>a[i][j];
		for(long long i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) o.push(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
			if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3]) p.push(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
			if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]) q.push(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		long long c=0;
		while(!o.empty()){
			c++;
			if(c>n/2) ans-=o.top();
			o.pop();
		}
		c=0;
		while(!p.empty()){
			c++;
			if(c>n/2) ans-=p.top();
			p.pop();
		}
		c=0;
		while(!q.empty()){
			c++;
//			cout<<c<<" "<<q.top()<<" ";
			if(c>n/2) ans-=q.top();
			q.pop();
//			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
