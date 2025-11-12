#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,t;
int a[200005][4];
priority_queue<int>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			q.push(a[i][1]);
		}
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=q.top();
			q.pop();
		}
		while(!q.empty())q.pop();
		cout<<ans<<"\n";
	}
	return 0;
}