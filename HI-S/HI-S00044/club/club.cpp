#include<bits/stdc++.h>
using namespace std;
int T;
const int N=1e5+5;
struct mmp{
	int thx,thy,thz;
}a[N];
struct mmp1{
	int thi,thj;
}pa[N],pb[N],pc[N];
bool cmpa(mmp1 n1,mmp1 n2){
	return n1.thj>n2.thj;
}
bool cmpb(mmp1 n3,mmp1 n4){
	return n3.thj>n4.thj;
}
bool cmpc(mmp1 n5,mmp1 n6){
	return n5.thj>n6.thj;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,ta=0,tb=0,tc=0,sum=0;
		int ka=0,kb=0,kc=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].thx,&a[i].thy,&a[i].thz);
			if(a[i].thx>=a[i].thy&&a[i].thx>=a[i].thz){
				ta++;
				ka++;
				pa[ka].thi=i;
				pa[ka].thj=a[i].thx;
			}
			if(a[i].thx<=a[i].thy&&a[i].thy>=a[i].thz){
				tb++;
				kb++;
				pb[kb].thi=i;
				pb[kb].thj=a[i].thy;
			}
			if(a[i].thz>=a[i].thy&&a[i].thx<=a[i].thz){
				tc++;
				kc++;
				pc[kc].thi=i;
				pc[kc].thj=a[i].thz;
			}
		}
		if(ta>n/2){
			sort(pa+1,pa+ka+1,cmpa);
			for(int i=n/2+1;i<=ka;i++){
				a[pa[i].thi].thx=0;
				if(a[pa[i].thi].thx<=a[pa[i].thi].thy&&a[pa[i].thi].thy>=a[pa[i].thi].thz){
					tb++;
					kb++;
					pb[kb].thi=i;
					pb[kb].thj=a[i].thy;
				}
				if(a[pa[i].thi].thz>=a[pa[i].thi].thy&&a[pa[i].thi].thy<=a[pa[i].thi].thz){
					tc++;
					kc++;
					pc[kc].thi=i;
					pc[kc].thj=a[i].thy;
				}
			}
		}
		if(tb>n/2){
			sort(pb+1,pb+kb+1,cmpb);
			for(int i=n/2+1;i<=kb;i++){
				a[pb[i].thi].thy=0;
				if(a[pa[i].thi].thz>=a[pa[i].thi].thy&&a[pa[i].thi].thy<=a[pa[i].thi].thz){
					kc++;
					pc[kc].thi=i;
					pc[kc].thj=a[i].thy;
				}
			}
		}
		for(int i=1;i<=ka;i++) sum+=pa[i].thj;
		for(int i=1;i<=kb;i++) sum+=pb[i].thj;
		for(int i=1;i<=kc;i++) sum+=pc[i].thj;
		cout<<sum<<endl;
	}
	return 0;
}
