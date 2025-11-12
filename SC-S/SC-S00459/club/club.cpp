#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4];
int b[N][2],cnt[4]; 
vector<int>mp[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		mp[1].clear();
		mp[2].clear();
		mp[3].clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
			b[i][0]=max(max(a[i][1],a[i][2]),a[i][3]);
			b[i][1]=a[i][1]+a[i][2]+a[i][3]-max(max(a[i][1],a[i][2]),a[i][3])-min(min(a[i][1],a[i][2]),a[i][3]);
		}
		int ans=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			int op;
			for(int j=1;j<=3;j++){
				if(a[i][j]==b[i][0]){
					op=j;
					break;
				}
			}cnt[op]++;
			ans+=b[i][0];
			mp[op].push_back(b[i][1]-b[i][0]);
		}for(int j=1;j<=3;j++){
			if(cnt[j]>n/2){
				sort(mp[j].begin(),mp[j].end());
				for(int i=cnt[j]-1;i>=n/2;i--){
					ans+=mp[j][i];
				}break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 