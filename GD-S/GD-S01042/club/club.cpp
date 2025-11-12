#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int t,n,ans,vis[N],cnta,cntb,cntc;
struct stt{
	int a,b,c;
}a[N];
struct stt2{
	int c;
	friend bool operator <(stt2 a,stt2 b){
		return a.c<b.c;
	} 
};
priority_queue<stt2>q;
signed main(){
	ios::sync_with_stdio(false); 
		cin.tie(0),cout.tie(0);
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				cnta++;
				ans+=a[i].a;
				vis[i]=0;
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				cntb++;
				ans+=a[i].b;
				vis[i]=1;
			}
			else{
				cntc++;
				ans+=a[i].c;
				vis[i]=2;
			}
		}
		for(int i=1;i<=n;i++){
			if(cnta>n/2&&vis[i]==0)q.push({max(a[i].b,a[i].c)-a[i].a}); 
			if(cntb>n/2&&vis[i]==1)q.push({max(a[i].a,a[i].c)-a[i].b}); 
			if(cntc>n/2&&vis[i]==2)q.push({max(a[i].a,a[i].b)-a[i].c}); 
		}
		if(cnta>n/2){cnta-=n/2;while(cnta--)ans+=q.top().c,q.pop();
		}
		if(cntb>n/2){
			cntb-=n/2;while(cntb--)ans+=q.top().c,q.pop();
		}
		if(cntc>n/2){
			cntc-=n/2;while(cntc--)ans+=q.top().c,q.pop();
		}
		cout<<ans<<"\n";
		memset(vis,0,sizeof vis);
		while(q.size())q.pop();
		memset(a,0,sizeof a);
		ans=0;
		cnta=cntb=cntc=0;
	}
	return 0;
}
