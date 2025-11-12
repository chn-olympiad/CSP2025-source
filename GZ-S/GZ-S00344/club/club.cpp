//GZ-S00344 贵阳市第一中学 甘梓辰
#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005][3],sz[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		priority_queue<int> q[3];
		sz[0]=sz[1]=sz[2]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int p=0;
			for(int j=1;j<=2;j++){
				if(a[i][j]>a[i][p]){
					p=j;
				} 
			}
			ans+=a[i][p];
			int d=-1;
			for(int j=0;j<3;j++){
				if(j!=p&&(d<0||a[i][j]>a[i][d])){
					d=j;
				}
			}
			q[p].push(a[i][d]-a[i][p]);
			sz[p]++;
//			cout<<"chk"<<i<<" "<<p<<" "<<d<<endl;
		}
		for(int i=0;i<3;i++){
			if(sz[i]>n/2){
				int k=sz[i]-n/2;
//				cout<<"!"<<i<<" "<<k<<endl;
				while(k--){
					ans+=q[i].top();
					q[i].pop();
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

