#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
int a[100005];
int b[100005];
int c[100005];
int to[100005];
bool vis[100005];
struct kkk{
	int id,w;
	bool operator <(const kkk& x)const{
		return w<x.w;
	} 
};
priority_queue<kkk> q;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++)to[i]=vis[i]=0;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;i++){
			int x=max({a[i],b[i],c[i]});
			if(x==a[i])cnt1++,to[i]=1,ans+=a[i];
			else if(x==b[i])cnt2++,to[i]=2,ans+=b[i];
			else cnt3++,to[i]=3,ans+=c[i];
		}if(cnt1>n/2){
			for(int i=1;i<=n;i++){
				if(to[i]==1){
					q.push({i,b[i]-a[i]}),q.push({i,c[i]-a[i]});
				}
			}while(cnt1>n/2){
				kkk x=q.top();
				q.pop();
				if(vis[x.id])continue;
				vis[x.id]=1;
				ans+=x.w;
				cnt1--;
			}
		}else if(cnt2>n/2){
			for(int i=1;i<=n;i++){
				if(to[i]==2){
					q.push({i,a[i]-b[i]}),q.push({i,c[i]-b[i]});
				}
			}while(cnt2>n/2){
				kkk x=q.top();
				q.pop();
				if(vis[x.id])continue;
				vis[x.id]=1;
				ans+=x.w;
				cnt2--;
			}
		}else if(cnt3>n/2){
			for(int i=1;i<=n;i++){
				if(to[i]==3){
					q.push({i,b[i]-c[i]}),q.push({i,a[i]-c[i]});
				}
			}while(cnt3>n/2){
				kkk x=q.top();
				q.pop();
				if(vis[x.id])continue;
				vis[x.id]=1;
				ans+=x.w;
				cnt3--;
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
