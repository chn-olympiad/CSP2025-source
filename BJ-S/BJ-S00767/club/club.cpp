#include<bits/stdc++.h>
using namespace std;
int t,n,a[102337],b[102337],c[102337],bel[102337],cnta,cntb,cntc,d[102337],res;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++)cin >> a[i] >> b[i] >> c[i];
		cnta=cntb=cntc=res=0;
		for(int i=1;i<=n;i++){
			if(max(a[i],max(b[i],c[i]))==a[i]){
				bel[i]=1;
				cnta++;
				res+=a[i];
			}else if(max(b[i],c[i])==b[i]){
				bel[i]=2;
				cntb++;
				res+=b[i];
			}else{
				bel[i]=3;
				cntc++;
				res+=c[i];
			}
		}
		if(cnta>n/2){
			for(int i=1;i<=n;i++){
				if(bel[i]==1){
					d[i]=min(a[i]-b[i],a[i]-c[i]);
				}else d[i]=23372337;
			}
			sort(d+1,d+n+1);
			for(int i=1;i<=cnta-n/2;i++){
				res-=d[i];
			}
		}else if(cntb>n/2){
			for(int i=1;i<=n;i++){
				if(bel[i]==2){
					d[i]=min(b[i]-a[i],b[i]-c[i]);
				}else d[i]=23372337;
			}
			sort(d+1,d+n+1);
			for(int i=1;i<=cntb-n/2;i++){
				res-=d[i];
			}
		}else if(cntc>n/2){
			for(int i=1;i<=n;i++){
				if(bel[i]==3){
					d[i]=min(c[i]-b[i],c[i]-a[i]);
				}else d[i]=23372337;
			}
			sort(d+1,d+n+1);
			for(int i=1;i<=cntc-n/2;i++){
				res-=d[i];
			}
		}
		cout << res << endl;
	}
	return 0;
}