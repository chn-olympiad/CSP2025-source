#include<bits/stdc++.h>
using namespace std;
struct my{
	int r,d;
}a[100005],b[100005],c[100005];
int t=0,n=0,cnta=0,cntb=0,cntc=0,a1[100005],b1[100005],c1[100005];
long long sum=0;
bool cmp(my x,my y){
	return x.d<y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&b1[i],&c1[i]);
			sum+=(max(a1[i],max(b1[i],c1[i])));
			a[i].r=i,b[i].r=i,c[i].r=i,a[i].d=a1[i],b[i].d=b1[i],c[i].d=c1[i];
			if((max(a1[i],max(b1[i],c1[i])))==a1[i]){
				cnta++;
				if(cnta>n/2){
					sort(a+1,a+cnta+1,cmp);
					sum-=a[i].d;
					if(cntb>=n/2){
						sum+=c1[a[1].r];
					}else if(cntc>=n/2){
						sum+=b1[a[1].r];
					}else{
						sum+=max(b1[a[1].r],c1[a[1].r]);
					}
				}
			}else if((max(a1[i],max(b1[i],c1[i])))==b1[i]){
				cntb++;
				if(cntb>n/2){
					sort(b+1,b+cntb+1,cmp);
					sum-=b[1].d;
					if(cnta>=n/2){
						sum+=c1[b[1].r];
					}else if(cntc>=n/2){
						sum+=a1[b[1].r];
					}else{
						sum+=max(c1[b[1].r],a1[b[1].r]);
					}
				}
			}else{
				cntc++;
				if(cntc>n/2){
					sort(c+1,c+cntc+1,cmp);
					sum-=c[1].d;
					if(cnta>=n/2){
						sum+=b1[c[1].r];
					}else if(cntb>=n/2){
						sum+=a1[c[1].r];
					}else{
						sum+=max(b1[c[1].r],a1[c[1].r]);
					}
				}
			}
		}
		printf("%lld",sum);
	}
	return 0;
}
