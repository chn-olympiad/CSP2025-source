#include<bits/stdc++.h>
using namespace std;
const int M=100010;
struct ps{
	int a,b,c;
}np[M];
int ka[M]={0},kb[M]={0},kc[M]={0};
int n;

void create();
bool cp(int p1,int p2){
	return p1<p2;
}
int solve();
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int what=1;what<=t;what++){
		create();
		printf("%d",solve());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void create(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d %d",&np[i].a,&np[i].b,&np[i].c);
}
int solve(){
	int cnta=0,cntb=0,cntc=0,sum=0,m;
	for(int i=1;i<=n;i++){
		m=max(np[i].a,max(np[i].b,np[i].c));
		sum += m;
		if(m==np[i].a){
			cnta++;
			ka[cnta]=np[i].a-max(np[i].b,np[i].c);
		}
		else if(m==np[i].b){
			cntb++;
			kb[cntb]=np[i].b-max(np[i].a,np[i].c);
		}
		else{
			cntc++;
			kb[cntc]=np[i].c-max(np[i].a,np[i].b);
		}
	}
	if(cnta>n/2){
		sort(ka+1,ka+cnta+1,cp);
		for(int i=1;i<=cnta-n/2;i++) sum-=ka[i];
	}
	if(cntb>n/2){
		sort(kb+1,kb+cntb+1,cp);
		for(int i=1;i<=cntb-n/2;i++) sum-=kb[i];
	}
	if(cntc>n/2){
		sort(kc+1,kc+cntc+1,cp);
		for(int i=1;i<=cntc-n/2;i++) sum-=kc[i];
	}
	return sum;
}
