#include<bits/stdc++.h>
using namespace std;
long t,n,q,a[10],b[10],o,m,d;
struct ab{
	int a,b,c,w,m;
}s[999999];
bool cmp (ab x,ab y){
	if(x.w==y.w){
		if(x.w==1)return x.a>y.a;
		if(x.w==2)return x.b>y.b;
		if(x.w==3)return x.c>y.c;
	}
	return x.w<y.w;
	
} 
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++){
	cin>>n;
	q=n/2;
	d=1;
	o=0;
	if(n==1){
		cin>>d;
		o=max(d,o);
		cin>>d;
		o=max(d,o);
		cin>>d;
		o=max(d,o);
		cout<<o<<endl;
		continue;
	}
	for(int j=1;j<=n;j++){
		cin>>s[j].a>>s[j].b>>s[j].c;
		s[j].m=max(s[j].a,max(s[j].b,s[j].c));
		if(s[j].b>=max(s[j].a,s[j].c)){
			s[j].w=2;
		}
		if(s[j].a>=max(s[j].b,s[j].c)){
			s[j].w=1;
		}
		if(s[j].c>=max(s[j].b,s[j].a)){
			s[j].w=3;
		}
	}
	sort(s+1,s+1+n,cmp);
/*
	for(int j=1;j<=n;j++){
		cout<<s[j].a<<" "<<s[j].b<<" "<<s[j].c<<" "<<s[j].w<<endl;
	}

//*/
	for(int j=0;j<=n;j++){
		if(s[j+1].a<=0||s[j+1].b<=0||s[j+1].c<=0){
			if(s[j+1].a>0&&s[j+1].b==0&&s[j+1].c>0) {
				if(s[j+1].a>s[j+1].c){
					if(a[1]<q) a[1]++,b[1]+=s[j+1].a;
					else if(a[3]<q) a[3]++,b[3]+=s[j+1].c;
				}
				else{
					if(a[3]<q) a[3]++,b[3]+=s[j+1].c;
					else if(a[1]<q) a[1]++,b[1]+=s[j+1].a;
				}		
			}
			if(s[j+1].a>0&&s[j+1].b>0&&s[j+1].c==0) {
				if(s[j+1].a>s[j+1].b){
					if(a[1]<q) a[1]++,b[1]+=s[j+1].a;
					else if(a[2]<q) a[2]++,b[2]+=s[j+1].b;
				}
				else{
					if(a[2]<q) a[2]++,b[2]+=s[j+1].b;
					else if(a[1]<q) a[1]++,b[1]+=s[j+1].a;
				}	
			}
			if(s[j+1].a==0&&s[j+1].b>0&&s[j+1].c>0) {
				if(s[j+1].c>s[j+1].b){
					if(a[3]<q) a[3]++,b[3]+=s[j+1].c;
					else if(a[2]<q) a[2]++,b[2]+=s[j+1].b;
				}
				else{
					if(a[2]<q) a[2]++,b[2]+=s[j+1].b;
					else if(a[3]<q) a[3]++,b[3]+=s[j+1].c;
				}	
			}
			if(s[j+1].a==0&&s[j+1].b==0&&s[j+1].c>0) {
				if(a[3]<q) a[3]++,b[3]+=s[j+1].c;	
			}
			if(s[j+1].a==0&&s[j+1].b>0&&s[j+1].c==0) {
				if(a[2]<q) a[2]++,b[2]+=s[j+1].b;	
			}
			if(s[j+1].a>0&&s[j+1].b==0&&s[j+1].c==0) {
				if(a[1]<q) a[1]++,b[1]+=s[j+1].a;	
			}
		}
		if(s[j].a>0&&s[j].b>0&&s[j].c>0){
			if(a[s[j].w]<q)a[s[j].w]++,b[s[j].w]=b[s[j].w]+s[j].m;
			else{
				if(s[j].w==1){
					if(s[j].b>=s[j].c){
						if(a[2]<q) a[2]++,b[2]=b[2]+s[j].b;
						else if(a[3]<q)a[3]++,b[3]=b[3]+s[j].c;
					}
					else if(a[3]<q)a[3]++,b[3]=b[3]+s[j].c;
				}
				if(s[j].w==2){
					if(s[j].a>=s[j].c){
						if(a[1]<q) a[1]++,b[1]=b[1]+s[j].a;
						else if(a[3]<q)a[3]++,b[3]=b[3]+s[j].c;
					}
					else if(a[3]<q)a[3]++,b[3]=b[3]+s[j].c;
				}
				if(s[j].w==3){
					if(s[j].b>=s[j].a){
						if(a[2]<q) a[2]++,b[2]=b[2]+s[j].b;
						else if(a[1]<q)a[1]++,b[1]=b[1]+s[j].a;
					}
					else if(a[1]<q)a[1]++,b[1]=b[1]+s[j].a;
				}
			}
		}
	}
	cout<<b[1]+b[2]+b[3]<<endl;
//	cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
//	cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
	b[1]=0;
	b[2]=0;
	b[3]=0;
	a[1]=0;
	a[3]=0;
	a[2]=0;
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




18

4

13





1


2

1 0 0

2 10 0



*/
