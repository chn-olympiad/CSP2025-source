#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
const int N=1e4+10;

//int love0d00
//1145141919810
//vector<pair<int,int> >v[N*20];
//priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >q;
//int dis[N*20];
//bool vis[N*20];
int f[N+100];
int find(int x){
	if(x==f[x]) return x;
	return  f[x]=find(f[x]);
}
struct node{
	int x,y,val;
}a[N*10];
int kl[N];
unordered_map<int,int> mp[N];
bool cmp(node x,node y){
	return x.val<y.val;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;

int cnt=0;

for(int i=1;i<=n+k;i++) f[i]=i;
for(int i=1;i<=m;i++){
	int x,y,z;
cin>>x>>y>>z;
a[++cnt].x=x,a[cnt].y=y,a[cnt].val=z;
//cout<<x<<' '<<y<<' '<<z<<' '<<cnt<<endl;
}

for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
		mp[i][j]=INT_MAX;
	}
}
for(int i=1;i<=k;i++){
	int c;
	cin>>c;
	for(int j=1;j<=n;j++){
		cin>>kl[j];
	}
	for(int j=1;j<=n;j++){
		for(int ki=j+1;ki<=n;ki++){
		mp[j][ki]=min(mp[j][ki],c+kl[j]+kl[ki]);
		//	cout<<' '<<j<<' '<<ki<<' '<<c+kl[j]+kl[ki]<<' '<<cnt<<endl;
		}
	}
}


for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
		a[++cnt].x=i,a[cnt].y=j,a[cnt].val=mp[i][j];
	}
}


sort(a+1,a+1+cnt,cmp);
int cn=0;
int ans=0;
for(int i=1;i<=cnt;i++){
	int x=find(a[i].x),y=find(a[i].y);
	if(x!=y){
	//cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].val<<endl;
		f[x]=y;
		cn++;
		ans=ans+a[i].val;
	}
	if(cn==n-1) break;
}
cout<<ans;















//	int cnt=0;
//	for(int i=1;i<=k;i++){
//		int c;
//		cin>>c;
//		cnt++;
//		for(int j=1;j<=n;j++){
//			int l;
//			cin>>l;
//			v[i+n].push_back({j,l+c});
//			v[j].push_back({i+n,l+c});				
//		}
//		
//	
//	
//	}
//	q.push({0,1});
//	memset(dis,0x3f,sizeof(dis));
//	dis[1]=0;
//	while(!q.empty()){
//		int fr=q.top().second;
//		q.pop();
//		if(vis[fr]) continue;
//		cout<<fr<<' '<<dis[fr]<<endl;
//		vis[fr]=true;
//		for(auto t:v[fr]){
//			int to=t.first,len=t.second;
//			if(!vis[to]&&len+dis[fr]<dis[to]){
//
//				dis[to]=dis[fr]+len;
//               cout<<to<<' '<<fr<<' '<<dis[to]<<endl;
//				q.push({dis[to],to});
//			}
//		}
//	}
//	int ans=INT_MAX,sum=0;
//		for(int j=1;j<=n;j++){
//			cout<<j<<' '<<dis[j]<<endl;
//			sum=max(sum,dis[j]);
//		}
//		ans=min(ans,sum);
//	
//	cout<<ans;
	
	
	
	return 0;
}
