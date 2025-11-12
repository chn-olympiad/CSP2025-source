#include<bits/stdc++.h>
using namespace std;
int t,n,a[4][400],dp[400][400],ans;
priority_queue<pair<int,int>,vector<pair<int,int> > > q1,q2,q3;
pair<int,int> temp;
bool vis[400];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[1][j],&a[2][j],&a[3][j]);
			temp.first=a[1][j];
			temp.second=j;
			q1.push(temp);
			temp.first=a[2][j];
			q2.push(temp);
			temp.first=a[3][j];
			q3.push(temp);
		}
		for(int i=1;i<=n;i++){
			int tmp1=q1.top().first;
			int tmp2=q2.top().first;
			int tmp3=q3.top().first;
			int mmax;
			mmax=max(tmp1,tmp2);
			mmax=max(mmax,tmp3);
			if(mmax==tmp1){
				if(!vis[q1.top().second]&&q1.size()>n/2){
					vis[q1.top().second]=1;
					q1.pop();
					ans+=tmp1;
				}
			}
			if(mmax=tmp2){
				if(!vis[q2.top().second]&&q2.size()>n/2){
					vis[q2.top().second]=1;
					q2.pop();
					ans+=tmp2;
				}
			}
			if(mmax=tmp3){
				if(!vis[q3.top().second]&&q3.size()>n/2){
					vis[q3.top().second]=1;
					q3.pop();
					ans+=tmp3;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*3
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
