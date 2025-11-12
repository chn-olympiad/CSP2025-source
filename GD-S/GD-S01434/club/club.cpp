#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,w[100005][3];
int cnt[3],ans0,ans;
priority_queue<int> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;cnt[0]=cnt[1]=cnt[2]=ans0=0;
		for(int i=1,fr;i<=n;++i){
			fr=0; 
			for(int j=0;j<3;++j)cin>>w[i][j],fr=(w[i][j]>w[i][fr]?j:fr);
			++cnt[fr],ans0+=w[i][fr];
		}
		if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
			cout<<ans0<<'\n';
			continue;
		}
		ans=0;
		for(int i=0;i<3;++i){
			ans0=0;while(!q.empty())q.pop();
			for(int j=1,ma1;j<=n;++j){
				ma1=0;
				for(int k=0;k<3;++k)
				if(i!=k)ma1=max(ma1,w[j][k]);
				if(j<=n/2)ans0+=w[j][i],q.emplace(ma1-w[j][i]);
				else{
					if(q.top()+w[j][i]>ma1)ans0+=w[j][i]+q.top(),q.pop(),q.emplace(ma1-w[j][i]);
					else ans0+=ma1;
				}
			}
			ans=max(ans,ans0);
		}
		cout<<ans<<'\n';
	}
	return 0;
}/*
·´»ÚÌ°ÐÄ 
*/
