#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
mt19937 engine(chrono::steady_clock().now().time_since_epoch().count());
const int MAXN=1e5+5;
int t,n;
int a[MAXN][3],num[3],col[MAXN];
long long Solve()
{
	long long Ans=0;
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++) {
		pair<int,int>res=mk(-1,0);
		for(int j=0;j<3;j++) {
			res=max(res,mk(a[i][j],j));
		}
		col[i]=res.second,Ans+=res.first;
//		cerr<<"col : "<<col[i]<<"\n";
		num[col[i]]++;
	}
	for(int id=0;id<3;id++) {
		if(num[id]>n/2) {
			vector<int>N;
			for(int i=1;i<=n;i++) {
				if(col[i]==id) {
					int Max=0;
					for(int j=0;j<3;j++) {
						if(j==id) continue;
						Max=max(Max,a[i][j]);
					}
					N.emplace_back(a[i][id]-Max);
				}
			}
			sort(N.begin(),N.end());
			for(int i=0;i<num[id]-(n/2);i++) Ans-=N[i];
		}
	}
	return Ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<3;j++) {
				cin>>a[i][j];
			}
		}
		cout<<Solve()<<"\n";
	}
	return 0;
}
