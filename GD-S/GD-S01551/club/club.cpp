#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100009][15],cnt[15],mx[100009],mxd[100009];priority_queue<int> q;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,ans=0;
	cin>>t;
	while(t--){
		while(!q.empty())q.pop();
		ans=0;
		cin>>n;
		for(int j=1;j<=3;j++)cnt[j]=0;
		for(int i=1;i<=n;i++){
			mx[i]=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				mx[i]=max(mx[i],a[i][j]);
			}
			ans+=mx[i];
			for(int j=1;j<=3;j++){
				if(a[i][j]==mx[i]){
					mxd[i]=j;
					cnt[j]++;
					break;
				}
			}
		}
		if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
			
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(cnt[j]>n/2&&mxd[i]==j){
						q.push(max(a[i][(j+1)%3+1],a[i][j%3+1])-a[i][j]);
						//printf("%lld ",max(a[i][(j+1)%3+1],a[i][j%3+1])-a[i][j]);
					}
				}
			}
			for(int j=1;j<=3;j++){
				while(cnt[j]>n/2){
					ans+=q.top();
					q.pop();
					cnt[j]--;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
