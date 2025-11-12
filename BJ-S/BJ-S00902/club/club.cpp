#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
int T,n,a[3][100010],id[100010];
int main(){
	cin.tie(0)->sync_with_stdio(0),fre("club");
	cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[0][i]>>a[1][i]>>a[2][i],id[i]=i;
		long long ans=0;
		long long res=0;
		int cnt[3]={0,0,0};
		for(int i=1;i<=n;++i){
			if(a[0][i]>=a[1][i]&&a[0][i]>=a[2][i])++cnt[0],res+=a[0][i];
			else if(a[1][i]>=a[0][i]&&a[1][i]>=a[2][i])++cnt[1],res+=a[1][i];
			else ++cnt[2],res+=a[2][i];
		}
		if(cnt[0]*2<=n&&cnt[1]*2<=n&&cnt[2]*2<=n)ans=res;
		else for(int op=0;op<3;++op){
			sort(id+1,id+n+1,[&](int x,int y){return a[op][x]-max(a[(op+1)%3][x],a[(op+2)%3][x])>a[op][y]-max(a[(op+1)%3][y],a[(op+2)%3][y]);});
			long long res=0;
			for(int i=1;i*2<=n;++i)res+=a[op][id[i]];
			for(int i=n/2+1;i<=n;++i)res+=max(a[(op+1)%3][id[i]],a[(op+2)%3][id[i]]);
			ans=max(ans,res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}