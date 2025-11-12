//±»npy´´·ÉÁË¡ª¡ªÍËÒÛ¡£ 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n,tot;
int id[5];
struct node{
	int ik,a,b,c,max_x,club;
	int ab,ac,ba,bc,ca,cb;
	string flag;
} x[N],ak[N],bk[N],ck[N];
bool cmpa(node o,node p){
	return min(o.ab,o.ac)<min(p.ab,p.ac);
}
bool cmpb(node o,node p){
	return min(o.ba,o.bc)<min(p.ba,p.bc);
}
bool cmpc(node o,node p){
	return min(o.ca,o.cb)<min(p.ca,p.cb);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cin >> T;
	scanf("%d",&T);
	while (T--){
		tot=0,id[1]=0,id[2]=0,id[3]=0;
//		cin >> n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			x[i].ik=i;
//			cin >> x[i].a >> x[i].b >> x[i].c;
			scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
			x[i].max_x=max(x[i].a,max(x[i].b,x[i].c));
			x[i].ab=x[i].a-x[i].b,x[i].ac=x[i].a-x[i].c,x[i].ba=x[i].b-x[i].a,x[i].bc=x[i].b-x[i].c,x[i].ca=x[i].c-x[i].a,x[i].cb=x[i].c-x[i].b;
			if (x[i].max_x==x[i].a) {
				x[i].flag="1";
				x[i].club=1;
				ak[++id[x[i].club]]=x[i];
			}
			else if (x[i].max_x==x[i].b) {
				x[i].flag="2";
				x[i].club=2;
				bk[++id[x[i].club]]=x[i];
			}
			else {
				x[i].flag="3";
				x[i].club=3;
				ck[++id[x[i].club]]=x[i];
			}
		}
//		cout << tot << ' ';
		sort(ak+1,ak+1+id[1],cmpa);
		if (id[1]>n/2){
//			cout << "!1" << '\n';
			for (int i=1;i<=id[1]-n/2;i++){
				if (x[ak[i].ik].flag.length()==3) continue;
				if (x[ak[i].ik].flag.length()==1){
					if (ak[i].ab<=ak[i].ac) {
						x[ak[i].ik].flag+="2";
						id[2]++;
						bk[id[2]]=x[ak[i].ik];
					}
					else {
						x[ak[i].ik].flag+="3";
						id[3]++;
						ck[id[3]]=x[ak[i].ik];
					}
				}
				else{
					int h=6-int(x[ak[i].ik].flag[0]-48)-int(x[ak[i].ik].flag[1]-48);
					if (h==1){
						x[ak[i].ik].flag+="2";
						id[2]++;
						bk[id[2]]=x[ak[i].ik];
					}
					else {
						x[ak[i].ik].flag+="3";
						id[3]++;
						ck[id[3]]=x[ak[i].ik];
					}
				}
			}
			for (int i=id[1]-n/2+1,j=1;i<=id[1];i++,j++){
				ak[j]=ak[i];
			}
			id[1]=n/2;
		}
		sort(bk+1,bk+1+id[2],cmpb);
		if (id[2]>n/2){
//			cout << "!2" << '\n';
			for (int i=1;i<=id[2]-n/2;i++){
				if (x[bk[i].ik].flag.length()==3) continue;
				if (x[bk[i].ik].flag.length()==1){
					if (bk[i].ba<=bk[i].bc) {
						x[bk[i].ik].flag+="1";
						id[1]++;
						ak[id[1]]=x[bk[i].ik];
					}
					else {
						x[bk[i].ik].flag+="3";
						id[3]++;
						ck[id[3]]=x[bk[i].ik];
					}
				}
				else {
					int h=6-int(x[bk[i].ik].flag[0]-48)-int(x[bk[i].ik].flag[1]-48);
					if (h==1){
						x[bk[i].ik].flag+="1";
						id[1]++;
						ak[id[1]]=x[bk[i].ik];
					}
					else {
						x[bk[i].ik].flag+="3";
						id[3]++;
						ck[id[3]]=x[bk[i].ik];
					}
				}	
			}
			for (int i=id[2]-n/2+1,j=1;i<=id[2];i++,j++){
				bk[j]=bk[i];
			}
			id[2]=n/2;
		}
		sort(ck+1,ck+1+id[3],cmpc);
		if (id[3]>n/2){
//			cout << "!3" << '\n';
			for (int i=1;i<=id[3]-n/2;i++){
				if (x[ck[i].ik].flag.length()==3) continue;
				if (x[ck[i].ik].flag.length()==1){
					if (ck[i].ca<=ck[i].cb) {
						x[ck[i].ik].flag+="1";
						id[1]++;
						ak[id[1]]=x[ck[i].ik];
					}
					else {
						x[bk[i].ik].flag+="2";
						id[2]++;
						bk[id[2]]=x[ck[i].ik];
					}
				}
				else {
					int h=6-int(x[ck[i].ik].flag[0]-48)-int(x[ck[i].ik].flag[1]-48);
					if (h==1){
						x[ck[i].ik].flag+="1";
						id[1]++;
						ak[id[1]]=x[ck[i].ik];
					}
					else {
						x[ck[i].ik].flag+="2";
						id[2]++;
						bk[id[2]]=x[ck[i].ik];
					}
				}	
			}
			for (int i=id[3]-n/2+1,j=1;i<=id[3];i++,j++){
				ck[j]=ck[i];
//				cout << ck[j].c << ' ';
			}
//			cout << '\n';
			id[3]=n/2;
			
		}
		sort(ak+1,ak+1+id[1],cmpa);
		if (id[1]>n/2){
//			cout << "!4" << '\n';
			for (int i=1;i<=id[1]-n/2;i++){
				if (x[ak[i].ik].flag.length()==3) continue;
				if (x[ak[i].ik].flag.length()==1){
					if (ak[i].ab<=ak[i].ac) {
						x[ak[i].ik].flag+="2";
						id[2]++;
						bk[id[2]]=x[ak[i].ik];
					}
					else {
						x[ak[i].ik].flag+="3";
						id[3]++;
						ck[id[3]]=x[ak[i].ik];
					}
				}
				else{
					int h=6-int(x[ak[i].ik].flag[0]-48)-int(x[ak[i].ik].flag[1]-48);
					if (h==1){
						x[ak[i].ik].flag+="2";
						id[2]++;
						bk[id[2]]=x[ak[i].ik];
					}
					else {
						x[ak[i].ik].flag+="3";
						id[3]++;
						ck[id[3]]=x[ak[i].ik];
					}
				}
			}
			for (int i=id[1]-n/2+1,j=1;i<=id[1];i++,j++){
				ak[j]=ak[i];
			}
			id[1]=n/2;
		}
		sort(bk+1,bk+1+id[2],cmpb);
		if (id[2]>n/2){
//			cout << "!5" << '\n';			
			for (int i=1;i<=id[2]-n/2;i++){
				if (x[bk[i].ik].flag.length()==3) continue;
				if (x[bk[i].ik].flag.length()==1){
					if (bk[i].ba<=bk[i].bc) {
						x[bk[i].ik].flag+="1";
						id[1]++;
						ak[id[1]]=x[bk[i].ik];
					}
					else {
						x[bk[i].ik].flag+="3";
						id[3]++;
						ck[id[3]]=x[bk[i].ik];
					}	
				}
				else {
					int h=6-int(x[bk[i].ik].flag[0]-48)-int(x[bk[i].ik].flag[1]-48);
					if (h==1){
						x[bk[i].ik].flag+="1";
						id[1]++;
						ak[id[1]]=x[bk[i].ik];
					}
					else {
						x[bk[i].ik].flag+="3";
						id[3]++;
						ck[id[3]]=x[bk[i].ik];
					}
				}	
			}
			for (int i=id[2]-n/2+1,j=1;i<=id[2];i++,j++){
				bk[j]=bk[i];
			}
			id[2]=n/2;
		}
		sort(ck+1,ck+1+id[3],cmpc);
		if (id[3]>n/2){
//			cout << "!6" << '\n';
			for (int i=1;i<=id[3]-n/2;i++){
				if (x[ck[i].ik].flag.length()==3) continue;
				if (x[ck[i].ik].flag.length()==1){
					if (ck[i].ca<=ck[i].cb) {
						x[ck[i].ik].flag+="1";
						id[1]++;
						ak[id[1]]=x[ck[i].ik];
					}
					else {
						x[bk[i].ik].flag+="2";
						id[2]++;
						bk[id[2]]=x[ck[i].ik];
					}
				}
				else {
					int h=6-int(x[ck[i].ik].flag[0]-48)-int(x[ck[i].ik].flag[1]-48);
					if (h==1){
						x[ck[i].ik].flag+="1";
						id[1]++;
						ak[id[1]]=x[ck[i].ik];
					}
					else {
						x[ck[i].ik].flag+="2";
						id[2]++;
						bk[id[2]]=x[ck[i].ik];
					}
				}	
			}
			for (int i=id[3]-n/2+1,j=1;i<=id[3];i++,j++){
				ck[j]=ck[i];
			}
			id[3]=n/2;
		}
		tot=0;
		for (int i=1;i<=id[1];i++){
			tot+=ak[i].a;
		}
		for (int i=1;i<=id[2];i++){
			tot+=bk[i].b;
		}
		for (int i=1;i<=id[3];i++){
			tot+=ck[i].c;
		}
//		cout << tot << '\n';
		printf("%d\n",tot);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
0 1 0

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
