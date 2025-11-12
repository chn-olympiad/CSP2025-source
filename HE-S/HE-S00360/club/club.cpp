#include<bits/stdc++.h>
#define int long long
#define Xuanbo return 0
using namespace std;
const int N=1e5+10;
int T;
int n;
int a[N][5];
int lmt;
int ans;
struct SOT{
	int num;
	int id;
	int val;
	bool operator<(const SOT &otr)const{
		return val>otr.val;
	}
};
vector<SOT> sot[N];
struct NODE{
	int id,val;
	int ntv,ntnum;
	int ntntv,ntntnum;
	bool operator<(const NODE &otr)const{
		return otr.val<val;
	}
};
priority_queue<NODE> q[5];
bool flagA=1,flagB=1;
priority_queue<int> qA;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	for(cin>>T;T;T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			sot[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j>=2&&a[i][j]!=0)flagA=0;
				if(j==1)qA.push(a[i][j]);
				sot[i].push_back({j,i,a[i][j]});
			}
			sort(sot[i].begin(),sot[i].end());
		}
		lmt=n/2;
		if(flagA){
			for(int i=1;i<=lmt;i++){
				ans+=qA.top();
				qA.pop();
			}
			cout<<ans<<'\n';
			while(!qA.empty()){
				qA.pop();
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			if(q[sot[i][0].num].size()<lmt){
				//cout<<"num:"<<sot[i][0].num<<" val:"<<sot[i][0].val<<'\n';
				q[sot[i][0].num].push({i,sot[i][0].val,sot[i][1].val,sot[i][1].num,sot[i][2].val,sot[i][2].num});
			}else{
				NODE low=q[sot[i][0].num].top();
				if(low.val+sot[i][1].val<low.ntv+sot[i][0].val){
					//cout<<"val:"<<sot[i][0].num<<'\n';
					q[sot[i][0].num].pop();
					q[sot[i][0].num].push({i,sot[i][0].val,sot[i][1].val,sot[i][1].num,sot[i][2].val,sot[i][2].num});
					q[low.ntnum].push({low.id,low.ntv,low.ntntv,low.ntntnum,INT_MAX,sot[i][0].num});
				}else{
					//cout<<"1:"<<low.val<<" 2:"<<low.ntv<<'\n';
					q[sot[i][1].num].push({i,sot[i][1].val,sot[i][2].val,sot[i][2].num,INT_MAX,sot[i][0].num});
				}
			}
		}
		for(int i=1;i<=3;i++){
			while(!q[i].empty()){
				ans+=q[i].top().val;
				//cout<<q[i].top().val<<" ";
				q[i].pop();
			}
		}
		cout<<ans<<'\n';
	}
	Xuanbo;
}
/*
1
2
10 9 8
4 0 0

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/
