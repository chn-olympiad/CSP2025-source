#include <bits/stdc++.h>
#define name "club"
using namespace std;
const int N=100007;
typedef priority_queue<int,vector<int>,greater<int>> pq;
pq q[3];
int a[N][3];
int main(){
	freopen(name".in","r",stdin);
	freopen(name".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t-->0){
		for(int i=0;i<3;i++) pq().swap(q[i]);
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<3;j++) cin>>a[i][j];
			int x=-1,y=-1,p=-1;
			for(int j=0;j<3;j++){
				if(a[i][j]>x) y=x,x=a[i][j],p=j;
				else if(a[i][j]>y) y=a[i][j];
			}
			q[p].push(x-y);
			ans+=x;
		}
		for(int i=0;i<3;i++) while(q[i].size()*2>n) ans-=q[i].top(),q[i].pop();
		cout<<ans<<'\n';
	}
	return 0;
}

//froepen("culb1.out","r",stdout)
//rp++
//ferepen("club1.in","r",stdin)
//CSP AK me
