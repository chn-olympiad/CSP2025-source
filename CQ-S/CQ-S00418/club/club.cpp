#include <bits/stdc++.h>
using namespace std;
namespace YSY{
	const int N=1e5+5;
	int T,n,tot[3];
	struct Choise{
		int val,Club;
		inline bool operator<(const  Choise &t) const {return val>t.val;}
	}a[N][3];
	struct Result{
		int stu,val;
		inline bool operator<(const Result &t) const {return val>t.val;}
	}res[3][N];
	inline void Solve(){
		cin>>n;
		int ans=0;tot[0]=tot[1]=tot[2]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++) cin>>a[i][j].val,a[i][j].Club=j;
			sort(a[i],a[i]+3);
			int v=a[i][0].val,c=a[i][0].Club;
			ans+=v,res[c][++tot[c]]={i,a[i][0].val-a[i][1].val};
		}
		int t=-1;
		for(int i=0;i<3;i++) if(tot[i]>n/2){t=i;break;}
		if(t==-1){cout<<ans<<'\n';return;}
		sort(res[t]+1,res[t]+tot[t]+1);
		while(tot[t]>n/2) ans-=res[t][tot[t]--].val;
		cout<<ans<<'\n';
	}
	inline void Main(){
		cin>>T;
		while(T--) Solve();
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	YSY::Main();
	return 0;
}

