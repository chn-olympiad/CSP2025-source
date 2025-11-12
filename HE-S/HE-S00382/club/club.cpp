#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
static int a[N][4],n,cnt[4],ans;
struct node{
	int op;
	int data;
	int num;
	bool flag;
}; 
vector<node>v[4];
static pair<int,int> get(node x){
	int minc1=1e9,p=1;
	for (int i=1;i<=3;++i){
		if (i==x.op)continue;
		else {
			if (x.data-a[x.num][i]<minc1&&x.data-a[x.num][i]>=0)p=i,minc1=x.data-a[x.num][i];
		}
	}	
	return make_pair(minc1,p);
}
bool cmp(node x,node y){
	pair<int,int> minc1=get(x),minc2=get(y);
	if (x.flag)return 0;
	else if (y.flag)return 1;
	return minc1.first<minc2.first;
}
void solve(int x){
	if (cnt[x]<=n/2)return;
	int k=cnt[x]-n/2;
	sort(v[x].begin(),v[x].end(),cmp);
	for (int i=0;i<v[x].size();++i){
		//cout<<v[x][i].op<<" "<<v[x][i].data<<" "<<v[x][i].num<<" "<<v[x][i].flag<<'\n';
		if (v[x][i].flag)continue;
		if (k==0)break;
		v[x][i].flag=1;
		pair<int,int> z=get(v[x][i]);
		ans-=z.first;cnt[z.second]++,cnt[x]--,k--;
		v[x][i].data=z.first;v[x][i].op=z.second;
//		cout<<z.first<<" "<<z.second<<'\n';
//		cout<<v[x][i].op<<" "<<v[x][i].data<<" "<<v[x][i].num<<" "<<v[x][i].flag<<'\n';
	}
}
void solve2(){
	cin>>n;
	memset(a,0,sizeof a);memset(cnt,0,sizeof cnt);ans=0;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=3;++j){
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=3;++i)v[i].clear();
	for (int i=1;i<=n;++i){
		int maxn=max(a[i][1],max(a[i][2],a[i][3]));
		if (maxn==a[i][1])ans+=a[i][1],cnt[1]++,v[1].push_back((node){1,a[i][1],i,0});
		else if (maxn==a[i][2])ans+=a[i][2],cnt[2]++,v[2].push_back((node){2,a[i][2],i,0});
		else ans+=a[i][3],cnt[3]++,v[3].push_back((node){3,a[i][3],i,0});
	}
	if (cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
		cout<<ans<<'\n';
		return;
	}
	else {
		int minn=1e9;
		for (int i=1;i<=20;++i){
			solve(1);solve(2);solve(3);
			if (cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
				minn=min(minn,ans);
			}
		}
		cout<<minn<<'\n';
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while (T--)solve2();
}
