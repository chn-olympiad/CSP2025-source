#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n;
struct Point{
	int z1,z2;
};
struct node{
	int z,id;
}a[N][10];
bool cmp(node x,node y){
	return x.z>y.z;
}
vector<Point> v[4];
priority_queue<int> q[4];
void solve(){
	
	int n,ans=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++)
		{
			cin>>a[i][j].z;
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+4,cmp);
	}
	for (int i=1;i<=n;i++){
		int _id=a[i][1].id;
		int res1=a[i][1].z,res2=a[i][2].z;
		
		
		if(v[_id].size()<n/2){
			v[_id].push_back(Point{res1,res2});
			q[_id].push(res2-res1);
			ans+=res1;
		}
		else{
			ans+=res2;
			int maxx=q[_id].top()+res1-res2;
			if(maxx>0){
				v[_id].push_back(Point{res1,res2});
				q[_id].pop();
				q[_id].push(res2-res1);
				ans+=maxx;
			}	
		}
		
	}
	cout <<ans<<endl;
	for (int i=1;i<=3;i++){
		v[i].clear();	
		while(!q[i].empty())
			q[i].pop();
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();	
	}
}
