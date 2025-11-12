#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int T,n;
int vis[N];
struct node{
	int x,flag,id;
	bool operator <(const node &c)const{
		return x>c.x;
	}
}a[N*3];
int b[N][5],d[5];
struct qqq{
	priority_queue<int,vector<int>,greater<int> >qi;
}q[3];
int se(int i){
	return b[i][0]+b[i][1]+b[i][2]-max(b[i][0],max(b[i][1],b[i][2]))-min(b[i][0],min(b[i][1],b[i][2]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	//a[1].x = 2;
	while(T--){
		//cout<<T<<" A"<<endl;
		long long ans = 0;
		for(int i = 0;i<3;++i){
			while(!q[i].qi.empty())q[i].qi.pop();
		}
		memset(d,0,sizeof(d));
		scanf("%d",&n);
		for(int i = 0;i<=n+1;++i){
			vis[i] = 0;
		}
		
		int cnt = 0;
		for(int i = 1;i<=n;++i){
			for(int j = 0;j<3;++j){
				int x;
				scanf("%d",&x);
				a[++cnt] = {x,j,i};
				b[i][j] = x;
			}
			//if(T!=4)cout<<i<<" "<<T<<endl;
		}
		
		sort(a+1,a+cnt+1);
		for(int i = 1;i<=cnt;++i){
			//cout<<i<<endl;
			auto [x,f,u] = a[i];
		//	cout<<x<<" "<<f<<" "<<u<<endl;
			if(vis[u])continue;
			if(d[f]>=n/2){
		//		cout<<"A"<<":";
				int st = q[f].qi.top();
				if(x-se(u)>st){
					q[f].qi.pop();
					ans-=st;
					ans+=x;
					q[f].qi.push(x-se(u));
					vis[u] = 1;
			//		cout<<"YES";
				}
			//	cout<<endl;
			}else{
				//cout<<"B"<<endl;
				d[f]++;
				ans+=x;
				q[f].qi.push(x-se(u));
				vis[u] = 1;
			}
		//	cout<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
