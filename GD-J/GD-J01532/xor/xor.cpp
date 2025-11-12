#include<bits/stdc++.h>
using namespace std;

struct pos{
	long long l,r;
};
pos c[500005];

long long n,a[500005],k,ans,u,mr,uk,cnt,ul,ur,mid;
unordered_map<long long,vector<long long> >t;

bool cmp(pos v,pos w){
	if(v.r==w.r) return v.l>w.l;
	return v.r<w.r;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	t[0].push_back(0);
	for(long long i=1;i<=n;i++){
		u^=a[i];
		t[u].push_back(i);
	}
	
	u=0;
	for(long long i=1;i<=n;i++){
		u^=a[i];
		uk=u^k;
		if(t.count(uk)!=0){
			if(t[uk][0]>=i) continue;
			ul=0,ur=(long long)(t[uk].size());
			while(ul+1<ur){
				mid=ul+(ur-ul)/2;
				if(t[uk][mid]<i) ul=mid;
				else ur=mid;
			}
			c[++cnt]={t[uk][ul]+1,i};
		}
	}
	sort(c+1,c+cnt+1,cmp);
	for(long long i=1;i<=cnt;i++){
	    if(c[i].l>mr){
	    	ans++;
	    	mr=c[i].r;
		}
	}
	cout<<ans;
	
	return 0;
}
