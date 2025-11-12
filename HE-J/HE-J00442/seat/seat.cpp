#include<bits/stdc++.h>
using namespace std;

template<typename T>inline void read(T&x){
	x=0; char c; int sign=1;
	do{c=getchar(); if(c=='-') sign=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	x*=sign;
}

int n,m,su,pos,lie,hang;
int a[110];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n); read(m);
	for(int i=1;i<=n*m;i++) read(a[i]);
	su=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==su){
			pos=i;
			break;
		}
	}
	if(pos%n==0){
		lie=pos/n;
		if(lie%2==1){
			hang=n;
		}else{
			hang=1;
		}
	}else{
		lie=pos/n+1;
		if(lie%2==1){
			hang=pos%n;
		}else{
			hang=n-(pos%n)+1;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
} 

