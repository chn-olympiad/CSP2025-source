#include <bits/stdc++.h>
using namespace std;
const int NR=1e5+5;
int t,n,a[NR][4],mx[NR],S=0,cnt[4],b[NR][4];
bool cmp(int x,int y){
	return a[S][x]>a[S][y];
}
void work(){
	cin>>n;
	for(int j=1;j<=3;j++)cnt[j]=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			b[i][j]=j;
		}
		S=i;
		sort(b[i]+1,b[i]+4,cmp);
		ans+=a[i][b[i][1]];
		cnt[b[i][1]]++;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]>n/2){
			priority_queue<int>q;
			for(int j=1;j<=n;j++){
				if(b[j][1]==i) 
					q.push(a[j][b[j][2]]-a[j][b[j][1]]);
			}
			for(int j=cnt[i];j>n/2;j--){
				ans+=q.top();
				q.pop();
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
		work();
	return 0;
}