#include<bits/stdc++.h>
using namespace std;
int n,t,x,y,a[100005],b[100005],c[100005],cnta,cntb,cntc;
long long ans;
struct egg{
	int a,b,c,cha;
}aa[100005];
bool cmp(egg x,egg y){
	return x.cha<y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		cnta=0;
		cntb=0;
		cntc=0;
		for(int i=1;i<=n;i++){
			cin>>aa[i].a>>aa[i].b>>aa[i].c;
			x=max(aa[i].a,max(aa[i].b,aa[i].c));
			y=aa[i].a+aa[i].b+aa[i].c-x-min(aa[i].a,min(aa[i].b,aa[i].c));
			aa[i].cha=x-y;
			ans+=x;
		}
		sort(aa+1,aa+n+1,cmp);
//		for(int i=1;i<=n;i++) cout<<aa[i].cha<<" ";
		for(int i=1;i<=n;i++){
			if(aa[i].a>=aa[i].b&&aa[i].a>=aa[i].c){
				cnta++;
				a[cnta]=i;
			}
			else{
				if(aa[i].b>=aa[i].c){
					cntb++;
					b[cntb]=i;
				}
				else{
					cntc++;
					c[cntc]=i;
				}
			}
		}
		if(cnta>n/2){
			for(int i=1;cnta>n/2;i++,cnta--){
				ans-=aa[a[i]].cha;
			}
		}
		if(cntb>n/2){
			for(int i=1;cntb>n/2;i++,cntb--){
				ans-=aa[b[i]].cha;
			}
		}
		if(cntc>n/2){
			for(int i=1;cntc>n/2;i++,cntc--){
				ans-=aa[c[i]].cha;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//aaaaaaaaaaa