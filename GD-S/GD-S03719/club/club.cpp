#include<bits/stdc++.h>
using namespace std;

//const int N=1e5+5;
//int f[N][3],T,n;
//bool b[3];
//
//signed main(){
//	freopen("club1.in","r",stdin);
////	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
//	cin>>T;
//	while(T--){
//		cin>>n;
//		for(int i=1;i<=n;i++)
//		cin>>f[i][1]>>f[i][2]>>f[i][3];
//		for(int i=2;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				f[i][j]=f[i][j]+max({f[i-1][1],f[i-1][2],f[i-1][3]});
//			}
//		}
//		cout<<max({f[n][1],f[n][2],f[n][3]})<<'\n';
//	}
//	return 0;
//}

#define f first
#define s second

const int N=1e5+5;
int T,n,b[5];
//struct paw{
//	int sum;
//	int idx;
//	bool operator<(const paw&x)const{
//		return sum>x.sum;
//	}
//}e[N][4];
long long ans;
priority_queue<pair<int,int> > q[N];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=0;i<=N;i++){
			while(!q[i].empty()) q[i].pop();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x;
				cin>>x;
				q[i].push({x,j});
			}
		}
		sort(q+1,q+n+1,[](priority_queue<pair<int,int>> &x,priority_queue<pair<int,int>> &y){
			return x.top().f>y.top().f;
		});
		for(int i=1;i<=n;i++){
			while(!q[i].empty()){	
				if(b[q[i].top().s]==n/2){
					if(!q[i-1].empty()){
						q[i-1].pop();
						ans=max(ans,(long long)(q[i-1].top().f+q[i].top().f));
					}
					q[i].pop();
					continue;
				}
				b[q[i].top().s]++;
				ans+=q[i].top().f;
				//cout<<q[i].top().f<<'\n';
				break;
			}
		}
		cout<<ans<<'\n';

//		sort(e+1,e+n+1);
//		
//		for(int i=1;i<=n;i++,cout<<'\n'){
//			for(int j=1;j<=3;j++)
//				cout<<e[i][j].sum<<' '<<e[i][j].idx<<'|';
//		}
//		sort(q+1,q+n+1,[](priority_queue<paw> &x,priority_queue<paw> &y){
//			return x.top().sum>y.top().sum;
//		});
//		for(int i=1;i<=n;i++){
//			while(!q[i].empty()){
//				cout<<q[i].top().sum<<' ';
//				q[i].pop();
//			}
//			cout<<'\n';
//		}
	}
	return 0;
}
/*
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
*/
