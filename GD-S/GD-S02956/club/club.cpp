#include<bits/stdc++.h>
using namespace std;
long long a[100005][3];
int cnt[3];
long long ans=0;
priority_queue<long long> q;
int main(){
	int t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		while(!q.empty()) q.pop();
		ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				cnt[0]++;
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				cnt[1]++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
				cnt[2]++;
			}
			ans+=max(max(a[i][0],a[i][1]),a[i][2]);
		}
//		cout<<cnt[0]<<"KLD";
		if(cnt[0]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
					q.push((max(a[i][1],a[i][2])-a[i][0]));
				}
			}
			while(cnt[0]>n/2){
				int u=q.top();
				ans+=u;
				q.pop();
				cnt[0]--;
			}
		}
		else if(cnt[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][0]){
					q.push((max(a[i][0],a[i][2])-a[i][1]));
				}
			}
			while(cnt[1]>n/2){
				int u=q.top();
				q.pop();
				ans+=u;
				cnt[1]--;
			}
		}
		else if(cnt[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
					q.push((max(a[i][0],a[i][1])-a[i][2]));
				}
			}
			while(cnt[2]>n/2){
				int u=q.top();
				ans+=u;
				cnt[2]--;
				q.pop();
			}	
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
} 
