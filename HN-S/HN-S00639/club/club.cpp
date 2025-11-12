#include<bits/stdc++.h>
using namespace std;
struct sy{
	int bh,dj;
};
bool cmp(sy p,sy q){
	return p.dj>q.dj; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,ansa=0,ansb=0,ansc=0,ans=0,a[205]={0},b[205]={0},c[205]={0};
		sy aa[205]={0},bb[205]={0},cc[205]={0};
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				if(ansa==n/2){
					int y=n/2,x=i;
					sort(aa+1,aa+1+y,cmp);
					if(aa[y].dj<a[x]-max(b[x],c[x])){
						ans+=a[x]-max(b[x],c[x])-aa[y].dj;
						aa[y].bh=x;
						aa[y].dj=a[x]-max(b[x],c[x]);
					}
				}
				else{
					ansa++;
					aa[ansa].bh=i;
					aa[ansa].dj=a[i]-max(b[i],c[i]);
					ans+=a[i]; 
				}
			} 
			if(c[i]>=b[i]&&c[i]>=a[i]){
				if(ansb==n/2){
					int y=n/2,x=i;
					sort(cc+1,cc+1+y,cmp);
					if(cc[y].dj<c[x]-max(b[x],a[x])){
						ans+=c[x]-max(b[x],a[x])-cc[y].dj;
						cc[y].bh=x;
						cc[y].dj=c[x]-max(b[x],a[x]);
					}
				}
				else{
					ansc++;
					cc[ansc].bh=i;
					cc[ansc].dj=c[i]-max(b[i],a[i]);
					ans+=c[i]; 
				}
			} 
			if(b[i]>=a[i]&&b[i]>=c[i]){
				if(ansb==n/2){
					int y=n/2,x=i;
					sort(bb+1,bb+1+y,cmp);
					if(bb[y].dj<b[x]-max(a[x],c[x])){
						ans+=b[x]-max(a[x],c[x])-bb[y].dj;
						bb[y].bh=x;
						bb[y].dj=b[x]-max(a[x],c[x]);
					}
				}
				else{
					ansb++;
					bb[ansb].bh=i;
					bb[ansb].dj=b[i]-max(c[i],a[i]);
					ans+=b[i];
				}
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}
