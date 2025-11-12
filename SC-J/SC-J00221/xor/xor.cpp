#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int ab[3001];
int bb[3001];
int qq,was;
//int yh(int a,int b){
//	string d;
//	string c;
//	int s=0,ss=0;
//	while(a>0){
//		s++;
//		c[s]=a%2;
//		a=a/2;
//	} 
//	while(b>0){
//		ss++;
//		d[ss]=b%2;
//		b=b/2;
//	}
//	if(s<ss){
//		swap(s,ss);
//		swap(c,d);
//	} //1110000 11111
//	string e;
//	for(int i=1;i<=ss;i++){
//		e[i]=(int(d[i])+int(c[i]))%2;
//	}
//	for(int i=ss+1;i<=s;i++){
//		e[i]=c[i];
//	}
//	int sss;
//	for(int i=1;i<=sss;i++){
//		sss=sss*2;
//		sss=sss+int(e[i]);
//	}
//	return sss;
//}
int abb(int a,int s){
//	cout<<a<<' '<<s<<endl;
	if(a>=qq+1){
	   return s;
	}
    if(bb[a]!=-1)
    return bb[a];
    int maxn=0;

	for(int i=a;i<=qq;i++){
	int ss=ab[i];
    int ssr=i+1;
    	if(ss==was){
		if(abb(ssr+1,s+1)>maxn)
		maxn=abb(ssr+1,s+1);
	}
    while(ss!=was&&ssr<=qq) {//yh(ss,ab[ssr])
    	ss=ss^ab[ssr];
    	ssr++;
	}
	if(ss==was){
		if(abb(ssr+1,s+1)>maxn)
		maxn=abb(ssr+1,s+1);
	}
	}
	return bb[a]=maxn;
}
int main(){
	freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
    int a,b,c,d,e,f,g;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
    	scanf("%d",&ab[i]);
    	bb[i]=-1;
	}
	bb[0]=-1;
	bb[a+1]=-1;
	qq=a;
	was=b;
	cout<<abb(1,0);
	return 0;
}