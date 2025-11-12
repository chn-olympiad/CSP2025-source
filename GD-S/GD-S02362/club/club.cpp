#include<iostream>
#include<cstring>
#include<queue>
#define pii pair<int,int>
#define ll long long
#define N 100005
using namespace std;

ll t,n,a[N][4],cnt[4],ans,nen[N][4],ne[N][4],c[N];

inline void init() {
	ans=0;
	memset(cnt,0,sizeof cnt);
}

inline void solve() {
	init();
	cin>>n;
	bool flagc=1;
	priority_queue<pii> q1,q2,q3;

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=3;j++) {
			cin>>a[i][j];
		}
		int mx=max(max(a[i][1],a[i][2]),a[i][3]);
		int mi=min(min(a[i][1],a[i][2]),a[i][3]);
		int mxn=1,minn=1,mid=1;
		if(a[i][1]==mx) mxn=1;
		else if(a[i][2]==mx) mxn=2;
		else mxn=3;
		if(a[i][1]==mi) minn=1;
		else if(a[i][2]==mi) minn=2;
		else minn=3;
		ans+=mx;
		cnt[mxn]++;
		if(mxn==minn) {continue;}
		if(mxn!=1&&minn!=1) mid=1;
		else if(mxn!=2&&minn!=2) mid=2;
		else mid=3;
		
//		cout<<mxn<<" "<<mid<<" "<<minn<<endl;

		// ne->一个数变成更小的消耗的代价
		ne[i][mxn]=a[i][mid]-a[i][mxn];
		ne[i][mid]=a[i][minn]-a[i][mid];
		ne[i][minn]=-0x3f3f3f3f;
		
		// nen->下一个数 
		nen[i][mxn]=mid;
		nen[i][mid]=minn;
		nen[i][minn]=0;
		
//		cout<<ne[i][mxn]<<" "<<ne[i][mid]<<" "<<ne[i][minn]<<endl;
		
		if(mxn==1) q1.push({ne[i][mxn],i});
		if(mxn==2) q2.push({ne[i][mxn],i});
		if(mxn==3) q3.push({ne[i][mxn],i});
		if(mid==1) q1.push({ne[i][mid],i});
		if(mid==2) q2.push({ne[i][mid],i});
		if(mid==3) q3.push({ne[i][mid],i});
		if(minn==1) q1.push({ne[i][minn],i});
		if(minn==2) q2.push({ne[i][minn],i});
		if(minn==3) q3.push({ne[i][minn],i}); 
	}
	while(max(max(cnt[1],cnt[2]),cnt[3])>n/2) {
		if(cnt[1]>n/2) {
//			cout<<1<<endl;
			cnt[1]--;
			pii x=q1.top();
			ans+=x.first;
			q1.pop();
			if(nen[x.second][1]==2) {
				q2.push({ne[x.second][2],x.second});
				cnt[2]++;
			} else {
				q3.push({ne[x.second][3],x.second});
				cnt[3]++;
			}
		}
		else if(cnt[2]>n/2) {
//			cout<<2<<endl;
			cnt[2]--;
			pii x=q2.top();
			ans+=x.first;
			q2.pop();
			if(nen[x.second][2]==1) {
				q1.push({ne[x.second][1],x.second});
				cnt[1]++;
			} else {
				q3.push({ne[x.second][3],x.second});
				cnt[3]++;
			}
		}
		else {
//			cout<<3<<endl;
			cnt[3]--;
			pii x=q3.top();
			ans+=x.first;
			q3.pop();
			if(nen[x.second][3]==1) {
				q1.push({ne[x.second][1],x.second});
				cnt[1]++;
			} else {
				q2.push({ne[x.second][2],x.second});
				cnt[2]++;
			}
		}
	}
	cout<<ans<<endl;
	return ;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {solve();}

	cout.flush();
	return 0;	
}
//I love ccf pls give me 100 pts
