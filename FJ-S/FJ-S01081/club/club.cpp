#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
struct solution{
	int n;
	vector<vector<int>> a;
	solution(int n,vector<vector<int>> a):n(n),a(a){
	} 
	bool flag;
	int solve(int id){
		int ans=0;
		priority_queue<int> pq; 
		for(int i=1;i<=n;i++){
			ans+=a[i][id];
			int temp=-INF;
			for(int j=1;j<=3;j++) if(j!=id){
				temp=max(temp,a[i][j]-a[i][id]);
			}
			pq.push(temp);
		}
		for(int i=1;i*2<=n;i++){
			if(pq.top()<0){
				flag=0;
			}
			ans+=pq.top();
			pq.pop();
		}
		return ans;
	}
	int main(){
		int ans=0;
		flag=1;
		for(int i=1;i<=3;i++){
			ans=max(ans,solve(i));
		}	
		if(flag){
			ans=0; 
			for(int i=1;i<=n;i++){
				ans+=max({a[i][1],a[i][2],a[i][3]});
			}
		}
		return ans;
	}
};
struct IO{
	int n;
	vector<vector<int>> a;
	IO(){
		cin>>n;
		a.resize(n+2,vector<int>(4));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
	}
	int ans;
	~IO(){
		cout<<ans<<"\n";
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		IO io;
		solution sol(io.n,io.a);
		io.ans=sol.main();
	}
	return 0;
}
