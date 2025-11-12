#include<bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define u32 unsigned int
#define u64 unsigned i64
#define Vec vector
i32 t;
i32 n;
i32 a[100517][3];
i32 asn[100517];
i32 ocst[100517];
i32 otr[100517];
i32 clb_p[3];
struct peo{
	i32 id;
	i32 asn;
	i32 otr;
	i32 ocst;
	bool operator<(peo p)const{
		return ocst<p.ocst;
	}
	bool operator>(peo p)const{
		return ocst>p.ocst;
	}
	bool operator<=(peo p)const{
		return ocst<=p.ocst;
	}
	bool operator>=(peo p)const{
		return ocst>=p.ocst;
	}
};
i32 main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		memset(clb_p,0,sizeof clb_p);
		cin>>n;
		i32 ans=0;
		for(i32 i=0;i<n;i++){
			asn[i]=0;
			otr[i]=-1;
			for(i32 j=0;j<3;j++){
				cin>>a[i][j];
				if(a[i][j]>a[i][asn[i]]){
					asn[i]=j;
				}
			}
			for(i32 j=0;j<3;j++){
				if(j==asn[i]){
					continue;
				}
				if(otr[i]==-1){
					otr[i]=j;
				}
				else if(a[i][j]>a[i][otr[i]]){
					otr[i]=j;
				}
			}
			clb_p[asn[i]]++;
			ans+=a[i][asn[i]];
			ocst[i]=a[i][asn[i]]-a[i][otr[i]];
		}
		i32 ov=-1;
		for(i32 c=0;c<3;c++){
			if(clb_p[c]>(n>>1)){
				ov=c;
			}
		}
		if(ov==-1){
			cout<<ans<<"\n";
			continue;
		}
		priority_queue<peo,Vec<peo>,greater<peo> > pq;
		for(i32 i=0;i<n;i++){
			if(asn[i]==ov){
				pq.push(peo{
					i,
					asn[i],
					otr[i],
					ocst[i]
				});
			}
		}
		while(clb_p[ov]>(n>>1)){
			peo tp=pq.top();
			pq.pop();
			clb_p[ov]--;
			clb_p[tp.otr]++;
			ans-=tp.ocst;
		}
		cout<<ans<<"\n";
	}
	return 0;
}