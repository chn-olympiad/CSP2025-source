#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5;

int cnt[5];
int n,m;

struct data {
	int w,pos;
	bool operator <(const data &b) {
		return w>b.w;
	}
};

struct node {
	int a,b,c;
} f[maxn+5];

bool cmp1(const node &aa,const node &bb) {
	return aa.a>bb.a;
}

bool cmp2(const node &aa,const  node &bb) {
	return aa.b>bb.b;
}

bool cmp3(const node &aa,const  node &bb) {
	return aa.c>bb.c;
}

int solve(int op) {
	if(op==1)sort(f+1,f+1+n,cmp1);
	else if(op==2)sort(f+1,f+1+n,cmp2);
	else sort(f+1,f+1+n,cmp3);
//	for(int i=1;i<=n;++i)
//	{
//		cout<<f[i].a<<" "<<f[i].b<<" "<<f[i].c<<"\n";
//	}
	int ans=0;
	data d[4];
	for(int i=1; i<=n; ++i) {
		d[1].w=f[i].a,d[1].pos=1;
		d[2].w=f[i].b,d[2].pos=2;
		d[3].w=f[i].c,d[3].pos=3;
		if(cnt[op]<n/2)
		{
			cnt[op]++;
			ans+=d[op].w;
			continue;
		}
		d[op].w=0xcfcfcfcf;
		sort(d,d+3);
		for(int j=2;j>=1;--j) {
			if(cnt[d[j].pos]<n/2) {
				ans+=d[j].w;
				cnt[d[j].pos]++;
				break;
			}
		}
	}
	cnt[1]=cnt[2]=cnt[3]=0;
	return ans;
}

int main() {
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; ++i)cin>>f[i].a>>f[i].b>>f[i].c;
		int ans=0;
		for(int i=1;i<=3;++i)
		ans=max(ans,solve(i));
		cout<<ans<<"\n";
	}
	return 0;
}
