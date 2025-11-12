//GZ-S000173 中央民族大学附属中学贵阳学校 张诗苑
#include<bits/stdc++.h>
using namespace std;
int n,T,c1,c2,c3;
long long m;
struct R{
	int f1,f2,f3;
}r[100020];
int l1[100020],l2[100020],l3[100020];

bool cmp1(int a,int b){
	return r[a].f1-max(r[a].f2,r[a].f3)>r[b].f1-max(r[b].f2,r[b].f3);
}

bool cmp2(int a,int b){
	return r[a].f2-max(r[a].f1,r[a].f3)>r[b].f2-max(r[b].f1,r[b].f3);
}

bool cmp3(int a,int b){
	return r[a].f3-max(r[a].f2,r[a].f1)>r[b].f3-max(r[b].f2,r[b].f1);

}

void cz(){
	for(int i=0;i<100020;i++){
		r[i]={0,0,0};
		l1[i]=0;
		l2[i]=0;
		l3[i]=0;
	}
	m=0;
	c1=0,c2=0,c3=0;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){ 
			scanf("%d%d%d",&r[i].f1,&r[i].f2,&r[i].f3);
			R w=r[i];
			if(w.f1==max(w.f1,max(w.f2,w.f3))) {l1[c1++]=i;m+=r[i].f1;}
			else if(w.f2==max(w.f1,max(w.f2,w.f3))){l2[c2++]=i;m+=r[i].f2;}
			else {l3[c3++]=i;m+=r[i].f3;}	
		}
		n>>=1;
		if(c1<=n && c2<=n && c3<=n)
			printf("%d\n",m);
		else{
			if(c1>n){
				sort(l1,l1+c1,cmp1);
				for(int i=n;i<c1;i++){
					m-=r[l1[i]].f1;
					m+=max(r[l1[i]].f2,r[l1[i]].f3);
				}
			}
			else if(c2>n){
				sort(l2,l2+c2,cmp2);
				for(int i=n;i<c2;i++){
					m-=r[l2[i]].f2;
					m+=max(r[l2[i]].f1,r[l2[i]].f3);
				}
			}
			else{
				sort(l3,l3+c3,cmp3);
				for(int i=n;i<c3;i++){
					m-=r[l3[i]].f3;
					m+=max(r[l3[i]].f2,r[l3[i]].f1);
				}
			}
			printf("%d\n",m);
		}
		cz();
	}
	return 0;
} 
