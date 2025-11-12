#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
const int M=2e4+100;
int L,n;
struct data{
	int a,b,c;
};
struct beta{
	int i,x,cha1,cha2,cha3;
};
bool cmp(beta a,beta b){
	return a.x>b.x; 
}
bool cmp1(beta a,beta b){
	return a.cha1<b.cha1; 
}
bool cmp2(beta a,beta b){
	return a.cha2<b.cha2; 
}
bool cmp3(beta a,beta b){
	return a.cha3<b.cha3; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&L);
	while(L--){
		beta ja[M]={},jb[M]={},jc[M]={};
		int cnt=0,j1=0,j2=0,j3=0,f=1; 
		data t[N]={};
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
			if(t[i].b!=0||t[i].c!=0) f=0;
			int m=max(t[i].a,max(t[i].b,t[i].c));
			if(m==t[i].a){ja[++j1].i=i;ja[j1].x=t[i].a;cnt+=t[i].a;}
			else if(m==t[i].b){jb[++j2].i=i;jb[j2].x=t[i].b;cnt+=t[i].b;}
			else if(m==t[i].c){jc[++j3].i=i;jc[j3].x=t[i].c;cnt+=t[i].c;}
		}
		if(n==2){
			int a1=t[1].a,a2=t[2].a,b1=t[1].b,b2=t[2].b,c1=t[1].c,c2=t[2].c;
			cnt=max(a1+b2,max(a1+c2,max(b1+a2,max(b1+c2,max(c1+a2,c1+b2)))));
			printf("%d\n",cnt);
		}
		else if(f){
			cnt=0;
			sort(ja+1,ja+j1+1,cmp);
			for(int i=1;i<=n/2;i++) cnt+=ja[i].x;
			printf("%d\n",cnt);
		}
		else{
			int o=n/2;
			if(j1<=o&&j2<=o&&j3<=o){printf("%d\n",cnt);continue;}
			for(int i=1;i<=j1;i++){
				int in=ja[i].i;
				ja[i].cha1=t[in].a-t[in].b;
				ja[i].cha2=t[in].a-t[in].c;
				ja[i].cha3=min(ja[i].cha1,ja[i].cha2);
			}
			for(int i=1;i<=j2;i++){
				int in=jb[i].i;
				jb[i].cha1=t[in].b-t[in].a;
				jb[i].cha2=t[in].b-t[in].c;
				jb[i].cha3=min(jb[i].cha1,jb[i].cha2);
			}
			for(int i=1;i<=j3;i++){
				int in=jc[i].i;
				jc[i].cha1=t[in].c-t[in].a;
				jc[i].cha2=t[in].c-t[in].b;
				jc[i].cha3=min(jc[i].cha1,jc[i].cha2);
			}
			if(j1>o&&j2<o&&j3<o){
				sort(ja+1,ja+j1+1,cmp3);
				int p=j1-o;
				for(int i=1;i<=p;i++){
					j1--;
					cnt-=ja[i].cha3;
					if(ja[i].cha3==ja[i].cha2&&j3<o) j3++;
					else j2++;
					if(j1<=o&&j2<=o&&j3<=o){printf("%d\n",cnt);break;}
				}
			}
			else if(j2>o&&j1<o&&j3<o){
				sort(jb+1,jb+j2+1,cmp3);
				int p=j2-o;
				for(int i=1;i<=p;i++){
					j2--;
					cnt-=jb[i].cha3;
					if(jb[i].cha3==jb[i].cha2&&j3<o) j3++;
					else j1++;
					if(j1<=o&&j2<=o&&j3<=o){printf("%d\n",cnt);break;}
				}
			}
		}
	}
	return 0;
}  
