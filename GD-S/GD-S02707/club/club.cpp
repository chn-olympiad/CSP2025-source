#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
#define REP(i,x,y) for(int (i)=(x);(i)>=(y);(i)--)
#define fastIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int N = 100003;
int T,n,m,ans,a[N][3],cnt[3];
priority_queue<int> q[3];
void INIT(){ m=n/2; ans=0;
	rep(i,0,2){ cnt[i]=0;
		while(!q[i].empty()) q[i].pop();
	}
}
void Solve(){ cin>>n; INIT(); int x;
	rep(i,1,n) cin>>a[i][0]>>a[i][1]>>a[i][2];
	rep(i,1,n){ x=max(a[i][0],max(a[i][1],a[i][2]));
		ans+=x;
		if(a[i][0]==x){
			++cnt[0]; q[0].push(max(a[i][1],a[i][2])-a[i][0]);
		}
		else if(a[i][1]==x){ 
			++cnt[1]; q[1].push(max(a[i][0],a[i][2])-a[i][1]);
		}
		else{
			++cnt[2]; q[2].push(max(a[i][0],a[i][1])-a[i][2]);
		}
	}
	if(cnt[0]>m){
		while(cnt[0]>m){ --cnt[0];
			ans+=q[0].top(); q[0].pop();
		}
	}
	if(cnt[1]>m){
		while(cnt[1]>m){ --cnt[1];
			ans+=q[1].top(); q[1].pop();
		}
	}
	if(cnt[2]>m){
		while(cnt[2]>m){ --cnt[2];
			ans+=q[2].top(); q[2].pop();
		}
	} cout<<ans<<'\n'; return;
}
int main(){ freopen("club.in","r",stdin); freopen("club.out","w",stdout); fastIO; cin>>T;
	while(T--) Solve();
	return 0;
}
