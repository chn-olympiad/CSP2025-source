#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+5;

struct node{
	int v,id,c;
	bool operator <(const node& x)const{
		return v>x.v;
	}
}b[N*3];

int n,a[N][3],ans,J,num[3],k;
vector<int>d[3];
bool vis[N];

int calc(int i){
	int x=max(max(a[i][0],a[i][1]),a[i][2]),y=min(min(a[i][0],a[i][1]),a[i][2]);
	return x-(a[i][0]+a[i][1]+a[i][2]-x-y);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		J=0;
		k=-1;
		for(int i=0;i<3;++i)num[i]=0,d[i].clear();
		ans=0;
		memset(vis,0,sizeof vis);
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			b[++J]={a[i][0],i,0};
			b[++J]={a[i][1],i,1};
			b[++J]={a[i][2],i,2};
		}
		sort(b+1,b+J+1);
		int cnt=0;
		for(int i=1,cnt;i<=J&&cnt<n;++i){
			if(vis[b[i].id])continue;
			ans+=b[i].v;
			num[b[i].c]++;
			//cout<<b[i].c<<" "<<calc(b[i].id)<<"\n";
			d[b[i].c].push_back(calc(b[i].id));
			vis[b[i].id]=1;
		}
		for(int i=0;i<3;++i)if(num[i]>n/2)k=i;
		if(k==-1){
			cout<<ans<<"\n";
			continue;
		}
		//cout<<k<<"\n";
		sort(d[k].begin(),d[k].end());
		for(int i=0;i<num[k]-n/2;++i)ans-=d[k][i];
		cout<<ans<<"\n";
	}
} 
