#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define ll long long
using namespace std;
const int N=1e5+10;
int a[N][5];
int cnt(int now,int x,int y) {return max(a[now][x],a[now][y]);}
int ch(int now,int x,int y) {return a[now][x]>a[now][y]?x:y;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int t;cin>>t;
	while(t--){
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q[5];
		ll n,ans=0;cin>>n;
		F(i,1,n) F(j,1,3) cin>>a[i][j];
		F(i,1,n){
			ll sum[5];
			F(j,1,3) sum[j]=0;
			F(j,1,3){
				if(q[j].size()>=n/2){
					sum[j]+=ans-q[j].top().first;
					int x=q[j].top().second;
					if(j==1) sum[j]+=cnt(x,2,3);
					if(j==2) sum[j]+=cnt(x,1,3);
					if(j==3) sum[j]+=cnt(x,1,2);
					sum[j]+=a[i][j];
				}else sum[j]=ans+a[i][j];
				//cout<<j<<" "<<q[j].size()<<" "<<sum[j]<<'\n';
			}
			int mx;
			(sum[1]>sum[2])?mx=1:mx=2;
			(sum[mx]>sum[3])?mx=mx:mx=3;
			ans=sum[mx];
			if(q[mx].size()>=n/2){
				int x=q[mx].top().second,fx;
				if(x==1) fx=ch(x,2,3);
				if(x==2) fx=ch(x,1,3);
				if(x==3) fx=ch(x,1,2);
				q[fx].push({a[x][fx],x});
				q[mx].pop();
			}
			q[mx].push({a[i][mx],i});
		}
		cout<<ans<<'\n';
	}
	return 0;
}





