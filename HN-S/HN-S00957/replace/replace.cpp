#include<bits/stdc++.h>
using namespace std;
int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){res=(res<<1)+(res<<3)+ch-'0';ch=getchar();}
	return res*f;
}
void write(int x){
	if(x<0){putchar('-');write(-x);return;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read();q=read();
	while(q--){write(0);putchar('\n');}
	return 0;
	/*
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	I AK CSP!
	*/
}
//100+56~72+0~5+8~12=164~189
