//made by @dhzsx

#include<bits/stdc++.h>
using namespace std;

const int MAX=100+5;
int a[MAX];

char gc(){return getchar();}
void pc(char c){putchar(c);}

void read(int &x){
	char c; bool f=false;
	for(;!isdigit(c=gc());)
		if(c=='-') f=true;
	for(x=c-'0';isdigit(c=gc());)
		x=x*10+c-'0';
	if(f) x=-x;
}

void write(int x){
	if(x==0){pc('0');return;}
	if(x<0){pc('-');x=-x;}
	char s[20]; int len=0;
	for(;x;x/=10) s[len++]=x%10+'0';
	for(;len--;) pc(s[len]);
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;
	read(n),read(m);
	for(int i=1;i<=n*m;++i){
		read(a[i]);
	}
	
	int k=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	
	int p;
	for(p=1;p<=n*m;++p){
		if(a[p]==k) break;
	}
	
	int r=(p-1)/n+1;
	int c=p-(r-1)*n;
	if(r%2==0) c=n+1-c;
	
	write(r),pc(' '),write(c); 
	return 0;
}
