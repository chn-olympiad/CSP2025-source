#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][5],tmp[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		int cnt[5]{};
		for(int i=1;i<=n;i++){
			tmp[i]=-1;
			for(int j=1;j<=3;j++) if(tmp[i]==-1||a[i][j]>a[i][tmp[i]]) tmp[i]=j;
			cnt[tmp[i]]++;
		}
		
		int tag=-1,ans=0;
		for(int i=1;i<=n;i++) ans+=a[i][tmp[i]];
		for(int i=1;i<=3;i++) if(cnt[i]>n/2) tag=i;
		if(tag==-1) cout<<ans<<"\n";
		else{
			int v1,v2;
			if(tag==1) v1=2,v2=3;
			else if(tag==2) v1=1,v2=3;
			else v1=1,v2=2;
			
			vector<int> nd;
			for(int i=1;i<=n;i++) if(tmp[i]==tag) nd.push_back(a[i][tag]-max(a[i][v1],a[i][v2]));
			sort(nd.begin(),nd.end());
			for(int i=0;i<cnt[tag]-n/2;i++) ans-=nd[i];
			
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
/*
是简单的贪心 
*/