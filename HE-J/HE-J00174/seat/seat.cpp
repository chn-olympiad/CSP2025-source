#include<bits/stdc++.h>
using namespace std;
long long read();
void write(long long a);
long long n,m,a,r,su=1;
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m*n;i++){
		a=read();
		if(i==1) r=a;
		else if(a>r) su++;
	}
	//cout<<su<<endl;
	if(su%n!=0){
	    write(su/n+1);
	    putchar(' ');
	    if((su/n+1)%2==1) write(su%n);
	    else write(n-su%n+1);
    }
    else{
    	write(su/n);
	    putchar(' ');
	    if((su/n)%2==1) write(n);
	    else write(1);
	}
	return 0;
}
long long read(){
	long long f=1,now=0;
	char c;
	c=getchar();
	while('0'>c||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		now=(now<<3)+(now<<1)+c-'0';
		c=getchar();
	}
	return now*f;
}
void write(long long a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>=10) write(a/10);
	putchar(a%10+'0');
}
