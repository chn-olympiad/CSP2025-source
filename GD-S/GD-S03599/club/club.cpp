#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{
	int x,id;
}a[N][5];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		priority_queue<int>q[5];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].x;
				a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+1+3,cmp);
			q[a[i][1].id].push(-(a[i][1].x-a[i][2].x));
			ans+=a[i][1].x;
		}
		while(int(q[1].size())>n/2){
			ans+=q[1].top();
			q[1].pop();
		}
		while(int(q[2].size())>n/2){
			ans+=q[2].top();
			q[2].pop();
		}
		while(int(q[3].size())>n/2){
			ans+=q[3].top();
			q[3].pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
