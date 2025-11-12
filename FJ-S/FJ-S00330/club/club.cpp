#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=1e5+10;
LL T,n,a[N],b[N],c[N],pa[N],pb[N],pc[N],ans,sa,sb,sc,d;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=sa=sb=sc=0;
		for(int i=1;i<=n;i++) pa[i]=pb[i]=pc[i]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]) pa[++sa]=a[i]-max(b[i],c[i]),ans+=a[i];
			else if(b[i]>=a[i]&&b[i]>=c[i]) pb[++sb]=b[i]-max(a[i],c[i]),ans+=b[i];
			else pc[++sc]=c[i]-max(a[i],b[i]),ans+=c[i];
		}
		if(sa>n/2){
			d=sa-n/2;
			sort(pa+1,pa+1+sa);
			for(int i=1;i<=d;i++) ans-=pa[i];
		}
		else if(sb>n/2){
			d=sb-n/2;
			sort(pb+1,pb+1+sb);
			for(int i=1;i<=d;i++) ans-=pb[i];
		}
		else if(sc>n/2){
			d=sc-n/2;
			sort(pc+1,pc+1+sc);
			for(int i=1;i<=d;i++) ans-=pc[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
