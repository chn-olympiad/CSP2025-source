#include<bits/stdc++.h>
using namespace std;
struct nd{
	int a,b,c,idx;
};
bool cmp(nd A,nd B){
	int amx=max(max(A.a,A.b),A.c),amn=min(min(A.a,A.b),A.c);
	int bmx=max(max(B.a,B.b),B.c),bmn=min(min(B.a,B.b),B.c);
	if(amx!=bmx) return amx>bmx;
    return amn<bmn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		vector<nd> v(n);
		vector<nd> cha(n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&v[i].a,&v[i].b,&v[i].c);
			int sum=v[i].a+v[i].b+v[i].c;
			cha[i].a=v[i].a-(sum-v[i].a);
			cha[i].b=v[i].b-(sum-v[i].b);
			cha[i].c=v[i].c-(sum-v[i].c);
			cha[i].idx=i;
		}
		sort(cha.begin(),cha.end(),cmp);
		int cnta=0,cntb=0,cntc=0,lim=n/2;
		long long ans=0;
		for(int i=0;i<n;i++){
			if(cha[i].a>=cha[i].b && cha[i].a>=cha[i].c){
				if(cnta==lim){
					if(cha[i].b>=cha[i].c){
						if(cntb==lim){
							cntc++;
							ans+=v[cha[i].idx].c;
						}
						else{
							cntb++;
							ans+=v[cha[i].idx].b;
						}
					}
					else{
						if(cntc==lim){
							cntb++;
							ans+=v[cha[i].idx].b;
						}
						else{
							cntc++;
							ans+=v[cha[i].idx].c;
						}
					}
				}
				else{
					cnta++;
					ans+=v[cha[i].idx].a;
				}
			}
			
			else if(cha[i].b>=cha[i].a && cha[i].b>=cha[i].c){
				if(cntb==lim){
					if(cha[i].a>=cha[i].c){
						if(cnta==lim){
							cntc++;
							ans+=v[cha[i].idx].c;
						}
						else{
							cnta++;
							ans+=v[cha[i].idx].a;
						}
					}
					else{
						if(cntc==lim){
							cnta++;
							ans+=v[cha[i].idx].a;
						}
						else{
							cntc++;
							ans+=v[cha[i].idx].c;
						}
					}
				}
				else{
					cntb++;
					ans+=v[cha[i].idx].b;
				}
			}
			
			else{
				if(cntc==lim){
					if(cha[i].a>=cha[i].b){
						if(cnta==lim){
							cntb++;
							ans+=v[cha[i].idx].b;
						}
						else{
							cnta++;
							ans+=v[cha[i].idx].a;
						}
					}
					else{
						if(cntb==lim){
							cnta++;
							ans+=v[cha[i].idx].a;
						}
						else{
							cntb++;
							ans+=v[cha[i].idx].b;
						}
					}
				}
				else{
					cntc++;
					ans+=v[cha[i].idx].c;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
