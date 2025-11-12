#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define ull unsigned long long
//#define connect_or_leave_oi return
int n,m,k;
struct node{
	int u,v;
	LL w;
	int id;
	friend bool operator <(node x,node y){
		return x.w<y.w;
	}
};
vector<node>tu;
const int N=1e5+100;
LL c[15];
int father[N];
int find_father(int x){
	return father[x]==x?x:father[x]=find_father(father[x]);
}
int bj[12];
vector<int>rem_id[12];
LL a[12][N];
int gx[12];
LL ans=LONG_LONG_MAX;
void tsxz(){
	for(int i=1;i<=n+k+10;i++)father[i]=i;
	for(int i=1;i<=k;i++){
		//tu.push_back({0,n+i,c[i]});
		for(int j=1;j<=n;j++){
			tu.push_back({n+i,j,a[i][j]});
		}
	}
	sort(tu.begin(),tu.end());
	for(int i=1;i<=n+k+10;i++)father[i]=i;
	int len=tu.size();
	ans=0;
	for(int i=0;i<len;i++){
		int u=tu[i].u;
		int v=tu[i].v;
		int l=find_father(u),r=find_father(v);
		if(l==r)continue;
		ans+=tu[i].w;
		father[l]=father[r];
	}
	return;
}
LL kls(vector<node>tu,LL sum,int cn){
	sort(tu.begin(),tu.end());
	LL an=sum;
	for(int i=1;i<=n+k+10;i++)father[i]=i;
	int len=tu.size(),cnt=0;
	for(int i=0;i<len;i++){
		int u=tu[i].u;
		int v=tu[i].v;
		if(cnt==n+cn-1)break;
		if(an>=ans)break;
		int l=find_father(u),r=find_father(v);
		if(l==r)continue;
		an+=tu[i].w;cnt++;
		father[l]=father[r];
	}
	return an;
}
void dfs(int now,vector<node>tu,bool yes,LL sum,int cnt){
	if(yes){
		sum+=c[now];
		for(int i=1;i<=n;i++){
			tu.push_back({n+now,i,a[now][i]});
		}
	}
	if(now==k){
		ans=min(ans,kls(tu,sum,cnt));return;
	}
	dfs(now+1,tu,1,sum,cnt+1);
	dfs(now+1,tu,0,sum,cnt);
	return;
}
void tscl(){
	for(int i=1;i<=n+k;i++)father[i]=i;
	LL ans2=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			tu.push_back({n+i,j,c[i]+a[i][j]});
		}
	}
	sort(tu.begin(),tu.end());int len=tu.size();
	for(int i=0;i<len;i++){
		if(tu[i].u>n)rem_id[tu[i].u-n].push_back(i);
	}
	for(int i=0;i<len;i++){
		int u=tu[i].u;
		int v=tu[i].v;
		int l=find_father(u),r=find_father(v);
		if(l==r)continue;
		ans2+=tu[i].w;
		father[l]=father[r];
		if(u>n&&v!=0){
			bj[u-n]++;
			gx[u-n]+=tu[i].w;
			if(bj[u-n]==1){
				for(int j=0;j<n;j++){
					tu[rem_id[u-n][j]].w-=c[u-n];
				}
				sort(tu.begin(),tu.end());
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(bj[i]<2)ans2-=gx[i];
	}
	ans=ans2;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		LL w;
		cin>>u>>v>>w;
		tu.push_back({u,v,w});
	}
	//sort(tu.begin(),tu.end());
	//LL ans1=0;
	//for(int i=0;i<len;i++){
	//	int u=tu[i].u;
	//	int v=tu[i].v;
	//	int l=find_father(u),r=find_father(v);
	//	if(l==r)continue;
	//	ans1+=tu[i].w;
	//	father[l]=father[r];
	//}
	bool ok=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)ok=0;
		//tu.push_back({0,n+i,c[i]});
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			//tu.push_back({n+i,j,w+c[i]});
		}
	}
	if(!ok){
		if((k>=5&&n>=1000&&m>=1000000))tscl();
		else dfs(0,tu,0,0,0);
	}
	else tsxz();
	cout<<ans;
	//connect_or_leave_oi 0;
	return 0;
}
