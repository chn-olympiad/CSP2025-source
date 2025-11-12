#include<bits/stdc++.h>
using namespace std;
int const N=1e8+10;

struct xs{
	int a;
	int x,y;
}s[105];

int n,m,h,fx=1;
int fz=1;
int cun;

bool  cmp(xs p,xs w){
	return p.a >w.a ;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	h=n*m;
	for(int i=1;i<=h;i++){
		cin>>s[i].a ;
	}
	cun=s[1].a;
	sort(s+1,s+h+1,cmp);
	for(int i=1;i<=h;i++){
		s[i].x =((i-1)/n)+1;
		if(s[i].x%2==1){
			s[i].y=i%n;
			if(i%n==0){
				s[i].y=n;
			}
		}else{
			s[i].y=n-(i%n)+1;
			if(i%n==0){
				s[i].y=1;
			}
		}
	}
	for(int i=1;i<=h;i++){
		if(s[i].a ==cun){
			cout<<s[i].x <<" "<<s[i].y ;
		}
	}
	return 0;
}