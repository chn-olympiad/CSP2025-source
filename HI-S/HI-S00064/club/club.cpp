#include <bits/stdc++.h>
#define GenshinImpact return
#define Start 0
using namespace std;

const int MAXN=3E5+114;
const int MAXM=3e6+114;

bool start_obagv;
int n,m,t,ans;
int ans1,ans2,ans3;
struct st{
	int a,b,c;
	int ab,ac,bc;
	int id,club;
}e[MAXM];
struct st1{//²ÖÎ» 
	int id,ab,ac;
}club1[MAXM];
struct st2{
	int id,ab,bc;
}club2[MAXM];
struct st3{
	int id,ac,bc;
}club3[MAXM];
bool end_obagv;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

inline bool cmp(st x,st y){
	return x.a>y.a;
} 
inline bool cmp1_ab(st1 x,st1 y){
	return x.ab<y.ab;
}
inline bool cmp1_ac(st1 x,st1 y){
	return x.ac<y.ac;
}
inline bool cmp2_ab(st2 x,st2 y){
	return x.ab<y.ab;
}
inline bool cmp2_bc(st2 x,st2 y){
	return x.bc<y.bc;
}
inline bool cmp3_bc(st3 x,st3 y){
	return x.bc<y.bc;
}
inline bool cmp3_ac(st3 x,st3 y){
	return x.ac<y.ac;
}

inline int find(int op){
	int k=0;
	if(op==1){
		sort(club1+1,club1+1+ans1,cmp1_ab);
		k=club1[1].id;
		sort(club1+1,club1+1+ans1,cmp1_ac);
		if(club1[k].ab>club1[1].ac) k=club1[1].id;
	}
	if(op==2){
		sort(club2+1,club2+1+ans2,cmp2_ab);
		k=club2[1].id;
		sort(club2+1,club2+1+ans2,cmp2_bc);
		if(club2[k].ab>club2[1].bc) k=club2[1].id;
	}
	if(op==3){
		sort(club3+1,club3+1+ans3,cmp3_bc);
		k=club1[1].id;
		sort(club3+1,club3+1+ans3,cmp3_ac);
		if(club3[k].bc>club3[1].ac) k=club3[1].id;
	}
	return k;
}

inline void tanxin(){
	for(int i=1;i<=n;i++){
		if(e[i].a>=e[i].b){
			if(e[i].a>=e[i].c){//1
				if(ans1>=n/2){
					int opt=find(1),k=min(min(min(e[i].ab,e[i].ac),e[opt].ab),e[opt].ac);
					ans+=e[i].a-k;
					if(k==e[opt].ab||k==e[opt].ac){
						club1[opt].id=e[i].id;
						club1[opt].ab=e[i].ab;
						club1[opt].ac=e[i].ac;
					}
				}
				else ans+=e[i].a,club1[++ans1].id=e[i].id,club1[ans1].ab=e[i].ab,club1[ans1].ac=e[i].ac; 
			}
			else{//3
				if(ans3>=n/2){
					int opt=find(3),k=min(min(min(e[i].bc,e[i].ac),e[opt].bc),e[opt].ac);
					ans+=e[i].c-k; 
					if(k==e[opt].bc||k==e[opt].ac){
						club3[opt].id=e[i].id;
						club3[opt].ac=e[i].ac;
						club3[opt].bc=e[i].bc;
					}
				}
				else ans+=e[i].c,club3[++ans3].id=e[i].id,club3[ans3].bc=e[i].bc,club3[ans3].ac=e[i].ac;
			}
		}
		else{
			if(e[i].b>=e[i].c){//2
				if(ans2>=n/2){
					int opt=find(2),k=min(min(min(e[i].ab,e[i].bc),e[opt].ab),e[opt].bc);
					ans+=e[i].b-k; 
					if(k==e[opt].bc||k==e[opt].ab){
						club2[opt].id=e[i].id;
						club2[opt].ab=e[i].ab;
						club2[opt].bc=e[i].bc;
					}
				}
				else ans+=e[i].b,club2[++ans2].id=e[i].id,club2[ans2].ab=e[i].ab,club2[ans2].bc=e[i].bc;
			}
			else{//3
				if(ans3>=n/2){
					int opt=find(3),k=min(min(min(e[i].bc,e[i].ac),e[opt].bc),e[opt].ac);
					ans+=e[i].c-k; 
					if(k==e[opt].bc||k==e[opt].ac){
						club3[opt].id=e[i].id;
						club3[opt].ac=e[i].ac;
						club3[opt].bc=e[i].bc;
					}
				}
				else ans+=e[i].c,club3[++ans3].id=e[i].id,club3[ans3].bc=e[i].bc,club3[ans3].ac=e[i].ac;
			}
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		int A=0,B=0;
		ans=ans1=ans2=ans3=0;
		n=read();
		for(int i=1;i<=n;i++){
			e[i].a=read();e[i].b=read();e[i].c=read();
			if(e[i].b!=0) A=1;
			e[i].ab=abs(e[i].a-e[i].b);
			e[i].ac=abs(e[i].a-e[i].c);
			e[i].bc=abs(e[i].b-e[i].c);
			e[i].id=i;
		}
		if(A==0){
			sort(e+1,e+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=e[i].a;
			printf("%d\n",ans);
			continue;
		}
		tanxin();
		printf("%d\n",ans);
	}
	GenshinImpact Start;
}
