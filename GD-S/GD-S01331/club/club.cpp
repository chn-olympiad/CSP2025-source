#include <iostream>
#include <algorithm>
using namespace std;
int n=0,as=0,bs=0,cs=0,ap=0,bp=0,cp=0;//as:a sum pleasure ,ap: a sum person
struct stmy{
	short a;
	short b;
	short c;
	char m;
}smy[100005];
int flag[100005];
bool cmp(stmy &A,stmy &B){
	return max(max(A.a,A.b),A.c)>max(max(B.a,B.b),B.c);
}
bool cmpa(stmy &A,stmy &B){
	return A.a>B.a;
}
bool cmpb(stmy &A,stmy &B){
	return A.b>B.b;
}
bool cmpc(stmy &A,stmy &B){
	return A.c>B.c;
}
bool cmpr(stmy &A,stmy &B){
	return max(max(A.a,A.b),A.c)<max(max(B.a,B.b),B.c);
}
void add(stmy s,int *ap,int *bp,int *cp,int *as,int *bs,int *cs,int *n){
	//test 
	//cout << "\n######\n" << s.a << " " << s.b << " " << s.c << " "<< s.m <<"\n######\n";
	//cout << "\n######\n" << *ap << " " << *bp << " " << *cp << " "<< *as << " " << *bs << " " << *cs << " "<<"\n######\n";

	if (s.m=='a'){
		if ((*ap)<(*n/2)){
			*ap+=1;
			*as+=s.a;
			//test
			//cout << "a\n";	
		}else if(s.b>=s.c){
			*bp+=1;
			*bs+=s.b;
			//test
			//cout << "b\n";
		}else{
			*cp+=1;
			*cs+=s.c;
			//test
			//cout << "c\n";
		}
	}else if(s.m=='b'){
		if (*bp<(*n/2)){
			*bp+=1;
			*bs+=s.b;
			//test
			//cout << "b\n";
		}else if(s.a>=s.c){
			*ap+=1;
			*as+=s.a;
			//test
			//cout << "a\n";
		}else{
			*cp+=1;
			*cs+=s.c;
			//test
			//cout << "c\n";
		}
	}else if(s.m=='c'){
		if (*cp<(*n/2)){
			*cp+=1;
			*cs+=s.c;
			//test
			//cout << "c\n";
		}else if(s.a>=s.b){
			*ap+=1;
			*as+=s.a;
			//test
			//cout << "a\n";
		}else{
			*bp+=1;
			*bs+=s.b;
			//test
			//cout << "b\n";
		}
	}
}
int run(){
	int n=0,as=0,bs=0,cs=0,ap=0,bp=0,cp=0;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> smy[i].a >> smy[i].b >> smy[i].c;
		if (smy[i].a>=smy[i].b && smy[i].a>=smy[i].c){
			smy[i].m='a';
		}if (smy[i].b>=smy[i].a && smy[i].b>=smy[i].c){
			smy[i].m='b';
		}if (smy[i].c>=smy[i].a && smy[i].c>=smy[i].b){
			smy[i].m='c';
		}
	} 
	sort(smy,smy+n,cmp);
	for (int i=0;i<n;i++){
		add(smy[i],&ap,&bp,&cp,&as,&bs,&cs,&n);
	}
	int s1=as+bs+cs;
	as=0;bs=0;cs=0;ap=0;bp=0;cp=0;
	sort(smy,smy+n,cmpr);
	for (int i=0;i<n;i++){
		add(smy[i],&ap,&bp,&cp,&as,&bs,&cs,&n);
	}
	int s2=as+bs+cs;
	as=0;bs=0;cs=0;ap=0;bp=0;cp=0;
	sort(smy,smy+n,cmpa);
	for (int i=0;i<n;i++){
		add(smy[i],&ap,&bp,&cp,&as,&bs,&cs,&n);
	}
	int s3=as+bs+cs;
	as=0;bs=0;cs=0;ap=0;bp=0;cp=0;
	sort(smy,smy+n,cmpb);
	for (int i=0;i<n;i++){
		add(smy[i],&ap,&bp,&cp,&as,&bs,&cs,&n);
	}
	int s4=as+bs+cs;
	as=0;bs=0;cs=0;ap=0;bp=0;cp=0;
	sort(smy,smy+n,cmpc);
	for (int i=0;i<n;i++){
		add(smy[i],&ap,&bp,&cp,&as,&bs,&cs,&n);
	}
	int s5=as+bs+cs;
	cout << max(s1,max(s2,max(s3,max(s4,s5)))) << "\n";
	return 0;
}
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for (int i=0;i<t;i++){
		run();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
