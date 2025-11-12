#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll in(){
	ll k=0;
	bool f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+(c^48);
		c=getchar();
	}
	return f?k:-k;
}
void out(ll x){
	ll pos=0;
	char buf[20];
	if(x<0){
		x=-x;
		putchar('-');
	}
	buf[pos++]=x%10^48;
	x/=10;
	while(x){
		buf[pos++]=x%10^48;
		x/=10;
	}
	while(pos){
		putchar(buf[--pos]);
	}
}
void outel(ll x){
	out(x);
	putchar('\n');
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n=in(),m=in(),a[110];
	ll num=n*m,cx=1;
	for(ll i=1;i<=num;i++){
		a[i]=in();
	}
	sort(a+2,a+num+1);
	for(ll i=num;i>=2;i--){
		if(a[i]>a[1])cx++;
		else break;
	}
	ll l=(cx-1)/n+1,h=(cx-1)%n+1;
	if(!(l&1)){
		h=m-h+1;
	}
	out(l);putchar(' ');out(h);
	fclose(stdin);
	fclose(stdout);
	return 0;
}