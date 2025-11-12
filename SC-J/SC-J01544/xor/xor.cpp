#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn=500005;
int n,k,ans,maxr=INT_MIN,a[maxn];
struct node1{
	int l,r;
	friend bool operator<(node1 n1,node1 n2){
		return n1.r>n2.r;
	}
};
priority_queue<node1> q;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				q.push({i,j});
				break;
			}
		}
	}
	while(!q.empty()){
		while(q.top().l<=maxr && !q.empty())q.pop();
		if(q.empty())break;
		ans++;
		maxr=q.top().r;
	}
	cout<<ans<<endl;
	return 0;
}