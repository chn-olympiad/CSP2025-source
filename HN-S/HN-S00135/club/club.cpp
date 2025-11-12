#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int a[N][3];
void sol(){
	int n,ans=0,s1=0,s2=0,s3=0;
	priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			int sec=max(a[i][1],a[i][2]);
			int mx=a[i][0];
			if(s1==n/2){
				int t=q1.top();
				q1.pop();
				q1.push(max(t,mx-sec));
				if(t<mx-sec)
					ans+=mx-t;
				else ans+=sec;
			}
			else 
				q1.push(mx-sec),ans+=mx,s1++;
			continue;
		}
		if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			int sec=max(a[i][0],a[i][2]);
			int mx=a[i][1];
			if(s2==n/2){
				int t=q2.top();
				q2.pop();
				q2.push(max(t,mx-sec));
				if(t<mx-sec)
					ans+=mx-t;
				else ans+=sec;
			}
			else 
				q2.push(mx-sec),ans+=mx,s2++;
			continue;
		}
		if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
			int sec=max(a[i][0],a[i][1]);
			int mx=a[i][2];
			if(s3==n/2){
				int t=q3.top();
				q3.pop();
				q3.push(max(t,mx-sec));
				if(t<mx-sec)
					ans+=mx-t;
				else ans+=sec;
			}
			else 
				q3.push(mx-sec),ans+=mx
			,s3++;
			continue;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)sol();
}