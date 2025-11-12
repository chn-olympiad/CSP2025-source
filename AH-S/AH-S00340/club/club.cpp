#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a1[100005],a2[100005],a3[100005];
long long ans;
int x;
priority_queue<int,vector<int>,greater<int>> pq1,pq2,pq3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		x=n/2;
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			int mx=max(a1[i],max(a2[i],a3[i]));
			if(mx==a1[i]){
				pq1.push(a1[i]);
				ans+=a1[i];
			}
			if(mx==a2[i]){
				pq2.push(a2[i]);
				ans+=a2[i];
			}
			if(mx==a3[i]){
				pq3.push(a3[i]);
				ans+=a3[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
