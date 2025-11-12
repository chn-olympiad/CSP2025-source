#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int f,s,t;
};
node a[200005];
struct edge{
	int w,id,lid;
};
int dp[100005];
edge b[500005];
int n,t;
int m1,m2,m3;
int mm[1000005];
struct jjj{
	int x,y;
};
vector <jjj> vv;
bool cmp(edge x,edge y){
	return x.w>y.w;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		vv.clear();
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		mm[1]=0;
		mm[2]=0;
		mm[3]=0;
		mm[0]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
			b[(i-1)*3+1].w=a[i].f-a[i].s;
			b[(i-1)*3+2].w=a[i].s-a[i].t;
			b[(i-1)*3+3].w=a[i].t-a[i].f;
			b[(i-1)*3+1].id=b[(i-1)*3+2].id=b[(i-1)*3+3].id=i;
			b[(i-1)*3+1].lid=1,b[(i-1)*3+2].lid=2,b[(i-1)*3+3].lid=3;
		}
		sort(b+1,b+3*n+1,cmp);
		for(int i=1;i<=3*n;i++){
			
			int x=b[i].id,y=b[i].lid;
//			cout<<x<<" "<<y<<endl;
			if(dp[x]==0&&mm[y]<n/2){
				vv.push_back(jjj{x,y});
				mm[y]++;
				dp[x]=1;
//				cout<<" knsfol"<<endl;
//				cout<<b[i].w<<" wfan"<<endl;
//				cout<<(i%n==0?n:i%n)<<endl<<i/3+(i%3!=0)<<endl;
			}
		}
		int ans=0;
		for(int i=0;i<vv.size();i++){
			int x=vv[i].x,y=vv[i].y;
//			cout<<x<<" "<<y<<endl;
//			cout<<a[x].f<<" "<<a[x].s<<" "<<a[x].t<<endl;
			if(y==3){
				ans+=a[x].t;
			}else if(y==2){
				ans+=a[x].s;
			}else if(y==1){
				ans+=a[x].f;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

