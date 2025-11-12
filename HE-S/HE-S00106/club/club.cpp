#include<bits/stdc++.h>
using namespace std;

int t,n,ans;
int cnt;
struct person{
	int d[5];
}p[100005];
int h[5];
bool vis[100005],can[5];
priority_queue<pair<int,int> > q,q1,q2;
void qing_(){
	while(!q.empty()){
		q.pop();
	}
	while(!q1.empty()){
		q1.pop();
	}
	while(!q2.empty()){
		q2.pop();
	}
	cnt=0;
	ans=0;
	memset(h,0,sizeof(h));
	memset(vis,0,sizeof(vis));
	memset(can,0,sizeof(can));
}
void cla_(){
	while(vis[q.top().second]) q.pop();
	while(vis[q1.top().second]) q1.pop();
	while(vis[q2.top().second]) q2.pop();
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		qing_();
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
//			int a=p[i].d[1];
//			int b=p[i].d[2];
//			int c=p[i].d[3];
			q.push(make_pair(a,i));
			q1.push(make_pair(b,i));
			q2.push(make_pair(c,i));
		}
		for(int i=1;i<=n;i++){
			cla_();
			int a=q.top().first;
			int b=q1.top().first;
			int c=q2.top().first;
			cout<<i<<' '<<a<<' '<<b<<' '<<c<<"\n";
			if(can[1]) a=-1;
			if(can[2]) b=-1;
			if(can[3]) c=-1;
			if(!can[1]&&a>=b&&a>=c){
				ans+=a;
				vis[q.top().second] = 1;
				h[1]++;
				if(h[1]==n/2) can[1]=1;
				q.pop();
			}else if(!can[2]&&b>=a&&b>=c){
				ans+=b;
				vis[q1.top().second] =1;
				h[2]++;
				if(h[2]==n/2) can[2]=1;
				q1.pop();
			}else if(!can[3]&&c>=a&&c>=b){
				ans+=c;
				vis[q2.top().second]=1;
				h[3]++;
				if(h[3]==n/2) can[3]=1;
				q2.pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
