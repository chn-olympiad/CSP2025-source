#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
int b[100005];
int c[100005];
priority_queue<pair<int,int>>q;
pair<int,int>max1(int x){
	priority_queue<pair<int,int>>pq;
	pq.push({a[x],1});
	pq.push({b[x],2});
	pq.push({c[x],3});
	return pq.top();
}
pair<int,int>max2(int x){
	priority_queue<pair<int,int>>pq;
	pq.push({a[x],1});
	pq.push({b[x],2});
	pq.push({c[x],3});
	pq.pop();
	return pq.top();
}
int club[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(club,0,sizeof(club));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			q.push({max1(i).first-max2(i).first,i});
		}
		int ans=0;
		while(!q.empty()){
			int k=q.top().second;
			q.pop();
			if(club[max1(k).second]<n/2){
				club[max1(k).second]++;
				ans+=max1(k).first;
			}
			else{
				club[max2(k).second]++;
				ans+=max2(k).first;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
