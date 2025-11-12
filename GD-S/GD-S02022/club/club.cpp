#include<bits/stdc++.h>
using namespace std;
int t;
struct m{
	int a,b,c;//ÂúÒâ¶È 
	int ab=-1,ac=-1,ba=-1,bc=-1,ca=-1,cb=-1;//²îÖµ 
}ren[100005];
bool cmpa(int a,int b){
	return ((ren[a].ab<ren[b].ab && ren[a].ab<ren[b].ac) ||(ren[a].ac<ren[b].ab && ren[a].ac<ren[b].ac));
}
bool cmpb(int a,int b){
	return ((ren[a].ba<ren[b].ba && ren[a].ba<ren[b].bc) ||(ren[a].bc<ren[b].ba && ren[a].bc<ren[b].bc));
}
bool cmpc(int a,int b){
	return ((ren[a].ca<ren[b].ca && ren[a].ca<ren[b].cb) ||(ren[a].cb<ren[b].ca && ren[a].cb<ren[b].cb));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		long long ans=0;
		cin>>n;
		int a[100005],b[100005],c[100005];
		int cta=1,ctb=1,ctc=1;
		for(int i=1;i<=n;i++){
			cin>>ren[i].a>>ren[i].b>>ren[i].c;
			if(ren[i].a>ren[i].b){
				if(ren[i].a>ren[i].c){
					ans=ans+ren[i].a;
					a[cta]=i;
					cta++;
					ren[i].ab=ren[i].a-ren[i].b;
					ren[i].ac=ren[i].a-ren[i].c;
				}else{
					ans=ans+ren[i].c;
					c[ctc]=i;
					ctc++;
					ren[i].ca=ren[i].c-ren[i].a;
					ren[i].cb=ren[i].c-ren[i].b;
				}
			}else{
				if(ren[i].b>ren[i].c){
					ans=ans+ren[i].b;
					b[ctb]=i;
					ctb++;
					ren[i].ba=ren[i].b-ren[i].a;
					ren[i].bc=ren[i].b-ren[i].c;
				}else{
					ans=ans+ren[i].c;
					c[ctc]=i;
					ctc++;
					ren[i].ca=ren[i].c-ren[i].a;
					ren[i].cb=ren[i].c-ren[i].b;
				}
			}
			
		}
		if(cta-1>n/2){
			sort(a+1,a+cta,cmpa);
			for(int i=1;i<=cta-1-n/2;i++){
				ans=ans-min(ren[a[i]].ab,ren[a[i]].ac);
			}
		}
		if(ctb-1>n/2){
			sort(b+1,b+ctb,cmpb);
			for(int i=1;i<=ctb-1-n/2;i++){
				ans=ans-min(ren[b[i]].ba,ren[b[i]].bc);
			}
		}
		if(ctc-1>n/2){
			sort(c+1,c+ctc,cmpc);
			for(int i=1;i<=ctc-1-n/2;i++){
				ans=ans-min(ren[c[i]].ca,ren[c[i]].cb);
			}
		}
		cout<<ans<<"\n";
	}
}
