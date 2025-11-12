#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][3];
struct node{
	int x,y;
	friend bool operator < (node a,node b){
		return a.y<b.y;
	}
};
priority_queue<node> q1,q2,q3;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		while(!q3.empty())q3.pop();
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2])q1.push({i,-a[i][0]+max(a[i][1],a[i][2])}),sum+=a[i][0];
			else if(a[i][1]>=a[i][2] && a[i][1]>=a[i][0])q2.push({i,-a[i][1]+max(a[i][0],a[i][2])}),sum+=a[i][1];
			else q3.push({i,-a[i][2]+max(a[i][0],a[i][1])}),sum+=a[i][2];
		}
		if((int)q2.size()>n/2)swap(q1,q2);
		if((int)q3.size()>n/2)swap(q1,q3);
		while(!q1.empty()&&(int)q1.size()>n/2){
			sum+=q1.top().y;
			q1.pop();
		}
		cout<<sum<<'\n';
	}
	return 0;
}
