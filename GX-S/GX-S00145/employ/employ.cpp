#include<bits/stdc++.h>
using namespace std;
int ttt,tt,n,na,nb,nc,ans[3],st[10005],t,head;
int f[100005];
struct stud{
	int a1,a2,a3,c,now;
}a[100005];
bool cmp(stud a,stud b){
	return a.c >= b.c;
}
void push(int x){
	st[++t] = x;
}
int pop(){
	return st[t--];
}/*
void checkInit(){
	for(int i=0;i<=n;i++){
		if(f[i]!=0) printf("\nf[%d]wrong!! ",i);
	}
}
void checkAfterChoose(int i,int ma,int mb,int h){
	printf(" \nf%d i%d now%d ma%d mb%d h%d  sth%d st:",f[i],i,a[i].now,ma,mb,h,st[h]);
	for(int i=1;i<=t;i++){
		printf("%d ",st[i]);
	}
}*/
int main(){
	freopen("employ.in","r",stdin);	freopen("employ.out","w",stdout);
	cin>>ttt;
	for(tt=0;tt<ttt;tt++){
		cin>>n;
		int maxn,nmax;
		for(int i=1;i<=n;i++){//zhao zui da he zui xiao de cha
			scanf("%d %d %d",&a[i].a1,&a[i].a2,&a[i].a3);
			if(a[i].a1>a[i].a2){maxn = a[i].a1;nmax = a[i].a2;}
			else{maxn = a[i].a2;nmax = a[i].a1;}
			if(a[i].a3 >maxn){nmax = maxn;maxn = a[i].a3;}
			else if(a[i].a3>nmax){nmax = a[i].a3;}
			a[i].c = maxn - nmax;
			//printf("c%d ",a[i].c);
		}if(tt!=0){
			
		sort(a+1,a+1+n,cmp);
		memset(f,0,sizeof(f));
		t=0;na=0;nb=na;nc = na;
	}
		for(int i=1;i<=n;i++){
			int ma = (max(a[i].a1,max(a[i].a2,a[i].a3)));//zhao shu zhi zui da de
			if(ma==a[i].a1){
				na++;
				a[i].now = 1;
			}
			else if(ma==a[i].a2) {nb++;a[i].now =2;}
			else {nc++;a[i].now =3;}//ji lu zai na ge club
			
					int h=t,mb;
			if(na>n/2||nb>n/2||nc>n/2){
					while(h){
						if(a[st[h]].now==a[i].now){
							mb = a[st[h]].c;
							a[st[h]].now = 4;//
							push(st[h]);
							break;
						}
						h--;
					}
					na+=(na>2?-1:0);
					nb+=(nb>2?-1:0);
					nc+=(nc>2?-1:0);
					f[i]=max(f[i-1]+ma-mb,f[i-1]+ma-a[i].c);
			}else{
				f[i] = f[i-1]+ma;
			}
			push(i);
			//checkAfterChoose(i,ma,mb,h);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
