#include<iostream>
#include<algorithm>
using namespace std;
struct edge {
	int st,ed;
	long long dis;
	int jihuo=0;
	int jik=0;
	bool use=0;
	int id;
};
edge bian[2000005];
int fa[20005];
bool isji[20005];
long long tmp[10005];
unsigned long long ans=0;
int n,m,k;
int cnt=0;

bool cmp(edge x,edge y) {
	if(x.jihuo>0 && isji[x.jik]) {
		x.dis-=x.jihuo;
		//bian[x.id].dis-=bian[x.id].jihuo;
		//bian[x.id].jihuo=0;
	}
	if(y.jihuo>0 && isji[y.jik]) {
		y.dis-=y.jihuo;
		//bian[y.id].dis-=bian[y.id].jihuo;
		//bian[y.id].jihuo=0;
	}
	return x.dis<y.dis;
}

void out() {
	for(int i=0; i<=n; ++i) {
		cout<<fa[i]<<' ';
	}
	cout<<endl;
	return ;
}
int findf(int x) {
	if(!fa[x]) {
		fa[x]=x;
		return x;
	}
	if(fa[x]==x) {
		//fa[x]=x;
		return x;
	}
	fa[x]=findf(fa[x]);
	return fa[x];
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; ++i) {
		cin>>bian[i].st>>bian[i].ed>>bian[i].dis;
		bian[i].id=i;
	}
//	for(int i=1;i<=m;++i){
//		cout<<bian[i].st<<' '<<bian[i].ed<<' '<<bian[i].dis<<endl;
//	}
//	cout<<"-----------------\n";
	++m;
	long long x;
	while(k--) {
		cin>>x;
		for(int j=1; j<=n; ++j) {
			cin>>tmp[j];
		}
		for(int i=1; i<=n; ++i) {
			for(int j=i+1; j<=n; ++j) {
				//if(i==j) continue;
				bian[m].dis=tmp[i]+tmp[j]+x;
				//bian[m].dis+=x;
				bian[m].jihuo=x;
				bian[m].jik=i+k;
				bian[m].st=i;
				bian[m].ed=j;
				bian[m].id=m;
				++m;
			}
		}
	}
	sort(bian+1,bian+m,cmp);
/*
	for(int i=1; i<=m; ++i) {
		cout<<bian[i].st<<' '<<bian[i].ed<<' '<<bian[i].dis<<' '<<bian[i].jihuo<<endl;
	}
	cout<<"-----------------\n";*/
	for(int i=1; i<m; ++i) {
		int fs=findf(bian[i].st),fe=findf(bian[i].ed);
		if(cnt==n-1) break; 
		if(fs!=fe && !bian[i].use) {
			//cout<<bian[i].st<<' '<<bian[i].ed<<' '<<bian[i].dis<<' '<<bian[i].jihuo<<' '<<bian[i].jik<<endl;
			fa[fs]=fe;
			ans+=bian[i].dis;
			bian[i].use=1;
			++cnt;
			if(bian[i].jihuo>0) {
				isji[bian[i].jik]=1;
				sort(bian+1,bian+m,cmp);
				i=1;
			}
		}
	}
	cout<<ans;
	return 0;
}

