#include <bits/stdc++.h>
using namespace std;
long long t,n,w;
long long m2=0,y2=0,d2=0,x1;
long long sh1=0,sh2=0,sh3=0,myd=0,l1=0,l2=0,l3=0;
struct hh{
	int m;
	int y;
	int d;
	int ky;
}s[10007];
/*bool an(hh x,hh z){
	return x.m>z.y;
}*/


int xx(int x){
	for(int i=1;i<=x;i++){
	
		cin>>s[i].m>>s[i].y>>s[i].d;
		s[i].ky=0;
	}

for(int j=1;j<=x;j++){	

	for(int i=1;i<=x;i++){
		m2=0;
		y2=0;
		d2=0;
		sh1=0;
		sh2=0;
		sh3=0;
		if(s[i].m>m2&&s[i].ky==0&&l1<n/2){
			m2=s[i].m;
			sh1=i;
		}
		if(s[i].y>y2&&s[i].ky==0&&l2<n/2){
			y2=s[i].y;
			sh2=i;
		}
		if(s[i].d>d2&&s[i].ky==0&&l3<n/2){
			d2=s[i].d;
			sh3=i;
		}
	
if(sh1==sh2&&sh2==sh3){
	myd+=max(s[sh1].m,max(s[sh2].y,s[sh3].d)); 
	s[sh1].ky=1;
	if(m2>y2&&m2>d2){
			l1++;
			continue;
		}
			if(y2>d2&&y2>m2){
				l2++;
				continue;
			}
			
				if(d2>m2&&d2>y2){
				l3++;
				continue;	
				
			
		
}}
if(sh1==sh2){
	l3++;
	myd+=d2;
	s[sh3].ky=1;
	myd+=max(s[sh1].m,s[sh2].y);
		s[sh1].ky=1;
		if(m2>y2){
			l1++;
			continue;
		}
		else{
			l2++;	continue;
		}}
if(sh3==sh2){
	l1++;
	s[sh1].ky=1;
	myd+=m2;
	myd+=max(s[sh3].d,s[sh2].y);
		s[sh3].ky=1;
		if(d2>y2){
			l3++;	continue;
		}
		else{
			l2++;	continue;
		}
}
	
if(sh3==sh1){
		l2++;
	s[sh2].ky=1;
	myd+=y2;
	myd+=max(s[sh3].d,s[sh1].m);
		s[sh3].ky=1;
		if(d2>m2){
			l3++;	continue;
		}
		else{
			l1++;	continue;
		}
}
	myd+=m2+y2+d2;
	s[sh1].ky=1;
	s[sh2].ky=1;
	s[sh3].ky=1;
	l1++;
	l2++;
	l3++;

}}
return myd;}

int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++){
	cin>>n;
	cout<<xx(n)<<endl;
	for(int i=1;i<=n;i++){
		s[i].ky=0;
		
	}
	myd=0;
	l1=0;
	l2=0;
	l3=0;
}
	
	return 0;
}
