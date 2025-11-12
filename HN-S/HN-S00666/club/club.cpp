#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int a[maxn][4];
int vis[4];
struct Node{
	int w,idmax,idmin;
	bool operator<(const Node &a) const{
		return w<a.w;
	}
};
priority_queue<Node>Q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++) {
			int maxx=0,maxx2=0,pos=0,pos2=0; 
			for(int j=1;j<=3;j++) {
				cin>>a[i][j];
				if(maxx < a[i][j]) {
					maxx2 = maxx,maxx = a[i][j];
					pos2 = pos,pos = j;//计算最大值和次大值所在的小组 
				} else if(a[i][j] > maxx2) {
					maxx2=a[i][j];
					pos2=j; 
				}
				//算出最大值和次大值 
			}
			sum+=maxx;
//			cout<<maxx<<' '<<maxx2<<'\n'; 
			Q.push({maxx-maxx2,pos,pos2});
		}
		while(!Q.empty()) {
			int diff=Q.top().w,id1=Q.top().idmax,id2=Q.top().idmin;
			Q.pop();
			if(vis[id1]<n/2) {
				vis[id1]++;
			} else {
				vis[id2]++;
				sum-=diff;
			}
		}
		for(int i=1;i<=3;i++) {
			vis[i]=0;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
