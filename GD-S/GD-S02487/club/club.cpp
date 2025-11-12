#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	int x;
}a[100010];
void px(int n,int m){
	if(n==1){
		int i,j;
		for(j=m;j>0;j--){
			for(i=1;i<j;i++){
				if(a[i].a>a[i+1].a)swap(a[i],a[i+1]);
			}
		}
	}
	else if(n==2){
		int i,j;
		for(j=m;j>0;j--){
			for(i=1;i<j;i++){
				if(a[i].b>a[i+1].b)swap(a[i],a[i+1]);
			}
		}
	}
	else if(n==3){
		int i,j;
		for(j=m;j>0;j--){
			for(i=1;i<j;i++){
				if(a[i].c>a[i+1].c)swap(a[i],a[i+1]);
			}
		}
	}
}
int main() {
	ifstream fin("club.in");
	ofstream fout("club.out");
	int nn;
	fin>>nn;
	int ii;
	int aa,bb,cc;
	int i;
	int n;
	for(ii=1; ii<=nn; ii++) {
		fin>>n;
		for(i=1; i<=n; i++) {
			fin>>aa;
			fin>>bb;
			fin>>cc;
			a[i].a=aa;a[i].b=bb;a[i].c=cc;a[i].x=i;
		}
		px(1,n);
		int ma[n+1][3]={};
		int j;
		j=1;
		for(i=n; i>0; i--) {
			ma[j][1]=a[i].a;
			ma[j][0]=a[i].x;
			j++;
		}
		px(2,n);
		int mb[n+1][3]={};
		j=1;
		for(i=n; i>0; i--) {
			mb[j][1]=a[i].b;
			mb[j][0]=a[i].x;
			j++;
		}
		px(3,n);
		int mc[n+1][3]={};
		j=1;
		for(i=n; i>0; i--) {
			mc[j][1]=a[i].c;
			mc[j][0]=a[i].x;
			j++;
		}
		int	ia,ib,ic,ans=0,ans_m=0;
		int wa,wb,wc;//位置
		int la,lb,lc;//最后一个
		for(ia=0; ia<=(n/2); ia++) {
			for(ib=0; ib<=(n/2); ib++) {
				for(ic=0; ic<=(n/2); ic++) {
					if((ia+ib+ic)==n) {
						ans=0;
						for(j=1;j<=n;j++)ma[j][2]=0;
						for(j=1;j<=n;j++)mb[j][2]=0;
						for(j=1;j<=n;j++)mc[j][2]=0;
						wa=1;
						wb=1;
						wc=1;
						la=ia;
						lb=ib;
						lc=ic;
						while(wa<=la) {
							while(ma[wa][2]==-1)wa++;
							j=1;
							while(j<=lb) {
								while(mb[j][2]==-1)j++;
								if(mb[j][0]==ma[wa][0]) {
									if((ma[wa][1]+mb[lb+1][1])>(ma[la+1][1]+mb[j][1])) {
										lb++;
										mb[j][2]=-1;
										break;
									} else {
										la++;
										ma[wa][2]=-1;
										break;
									}
								}
								if(la>n)break;
								if(lb>n)break;
								if(lc>n)break;
								j++;
							}
							j=1;
							while(j<=lc) {
								while(mc[j][2]==-1)j++;
								if(mc[j][0]==ma[wa][0]) {
									if((ma[wa][1]+mc[lc+1][1])>(ma[la+1][1]+mc[j][1])) {
										lc++;
										mc[j][2]=-1;
										break;
									} else {
										la++;
										ma[wa][2]=-1;
										break;
									}
								}
								if(la>n)break;
								if(lb>n)break;
								if(lc>n)break;
								j++;
							}
							wa++;
						}
						while(wb<=lb) {
							while(mb[wb][2]==-1)wb++;
							j=1;
							while(j<=lc) {
								while(mc[j][2]==-1)j++;
								if(mc[j][0]==mb[wb][0]) {
									if((mb[wb][1]+mc[lc+1][1])>(mb[lb+1][1]+mc[j][1])) {
										lc++;
										mc[j][2]=-1;
										break;
									} else {
										lb++;
										mb[wb][2]=-1;
										break;
									}
								}
								if(la>n)break;
								if(lb>n)break;
								if(lc>n)break;
								j++;
							}
							j=1;
							while(j<=la) {
								while(ma[j][2]==-1)j++;
								if(ma[j][0]==mb[wb][0]) {
									if((mb[wb][1]+ma[la+1][1])>(mb[lb+1][1]+ma[j][1])) {
										la++;
										ma[j][2]=-1;
										break;
									} else {
										lb++;
										mb[wb][2]=-1;
										break;
									}
								}
								if(la>n)break;
								if(lb>n)break;
								if(lc>n)break;
								j++;
							}
							wb++;
						}
						while(wc<=lc) {
							while(mc[wc][2]==-1)wc++;
							j=1;
							while(j<=lb) {
								while(mb[j][2]==-1)j++;
								if(mb[j][0]==mc[wc][0]) {
									if((mc[wc][1]+mb[lb+1][1])>(mc[lc+1][1]+mb[j][1])) {
										lb++;
										mb[j][2]=-1;
										break;
									} else {
										lc++;
										mc[wc][2]=-1;
										break;
									}
								}
								if(la>n)break;
								if(lb>n)break;
								if(lc>n)break;
								j++;
							}
							j=1;
							while(j<=la) {
								while(ma[j][2]==-1)j++;
								if(ma[j][0]==mc[wc][0]) {
									if((mc[wc][1]+ma[la+1][1])>(mc[lc+1][1]+ma[j][1])) {
										la++;
										ma[j][2]=-1;
										break;
									} else {
										lc++;
										mc[wc][2]=-1;
										break;
									}
								}
								if(la>n)break;
								if(lb>n)break;
								if(lc>n)break;
								j++;
							}
							wc++;
						}
						if(la>n)continue;
						if(lb>n)continue;
						if(lc>n)continue;
						wa=wb=wc=1;
						ans=0; 
						while(wa<=la){
							while(ma[wa][2]==-1){
								wa++;	
							}
							ans+=ma[wa][1];
							wa++;
						}
						while(wc<=lc){
							while(mc[wc][2]==-1)wc++;
							ans+=mc[wc][1];
							wc++;
						}
						while(wb<=lb){
							while(mb[wb][2]==-1)wb++;
							ans+=mb[wb][1];
							wb++;
						}	
						if(ans>ans_m){
							ans_m=ans;
						}
					}
				}
			}
		}
		fout<<ans_m<<'\n';
	}
	return 0;
}
