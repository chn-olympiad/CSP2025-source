#include <bits/stdc++.h>

using namespace std;
struct member{
	int a;
	int b;
	int c;
}mem[110000];
member aa[110000];
member bb[110000];
member cc[110000];
int fenpei(member g){
	if(g.a>g.b&&g.a>g.c) return 1;
	if(g.b>g.a&&g.b>g.c) return 2;
	if(g.c>=g.b&&g.c>=g.a) return 3;
}
bool cmpa(member x,member y){
	if(x.a<y.a){
		swap(x.a,y.a);
		swap(x.b,y.b);
		swap(x.c,y.c);
	}
}
bool cmpb(member x,member y){
	if(x.b<y.b){
		swap(x.a,y.a);
		swap(x.b,y.b);
		swap(x.c,y.c);
	}
}
bool cmpc(member x,member y){
	if(x.c<y.c){
		swap(x.a,y.a);
		swap(x.b,y.b);
		swap(x.c,y.c);
	}
}
int al,bl,cl;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	for(int q=0;q<t;q++){
		al=0,bl=0,cl=0;
		int n;
		cin >>n;
		for(int i=0;i<n;i++){
			cin >>mem[i].a;
			cin >>mem[i].b;
			cin >>mem[i].c;
			if(fenpei(mem[i])==1) aa[al++]=mem[i];
			if(fenpei(mem[i])==2) bb[bl++]=mem[i];
			if(fenpei(mem[i])==3) cc[cl++]=mem[i];
		}
		sort(aa,aa+al-1,cmpa);
		sort(bb,bb+bl-1,cmpb);
		sort(cc,cc+cl-1,cmpc);
		if(al+1>n/2){
			for(int i=0;i<(al+1)-n/2-1;i++){
				aa[i].a=0;
				if(fenpei(mem[i])==2) bb[bl++]=mem[i];
				if(fenpei(mem[i])==3) cc[cl++]=mem[i];
			}
		}else if(bl+1>n/2){
			for(int i=0;i<(bl+1)-n/2-1;i++){
				bb[i].b=0;
				if(fenpei(mem[i])==1) aa[al++]=mem[i];
				if(fenpei(mem[i])==3) cc[cl++]=mem[i];
			}
		}else if(cl+1>n/2){
			for(int i=0;i<(cl+1)-n/2-1;i++){
				cc[i].c=0;
				if(fenpei(mem[i])==1) aa[al++]=mem[i];
				if(fenpei(mem[i])==2) bb[bl++]=mem[i];
			}
		}
		int ans=0;
		for(int i=0;i<al;i++){
			ans+=aa[i].a;
			aa[i]={0,0,0};
		}
		for(int i=0;i<bl;i++){
			ans+=bb[i].b;
			bb[i]={0,0,0};
		}
		for(int i=0;i<cl;i++){
			ans+=cc[i].c;
			cc[i]={0,0,0};
		}
		for(int i=0;i<n;i++){
			mem[i]={0,0,0};
		}
		cout <<ans<<endl;
	}	
} 
     