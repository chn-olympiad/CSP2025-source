#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],e[4],id1[N],id2[N],ans,ls[N];
pair<int,int> p[4];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		ans=0;
		memset(e,0,sizeof e);
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			p[1]=make_pair(a[i][1],1);
			p[2]=make_pair(a[i][2],2);
			p[3]=make_pair(a[i][3],3);
			sort(p+1,p+3+1);
			id1[i]=p[3].second;
			e[id1[i]]++;
			ans+=p[3].first;
			id2[i]=p[2].second;
		}
		for(int oo=1;oo<=3;oo++) if(e[oo]>n/2) {
			int cnt=0;
			for(int i=1;i<=n;i++) if(id1[i]==oo) {
				ls[++cnt]=a[i][id1[i]]-a[i][id2[i]];
			}
			sort(ls+1,ls+cnt+1);
			for(int i=1;i<=e[oo]-n/2;i++) ans-=ls[i];
			break ;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

