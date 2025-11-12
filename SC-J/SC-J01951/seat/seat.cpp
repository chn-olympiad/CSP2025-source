#include<bits/stdc++.h>
using namespace std;
int s,f;
char ch;
inline int read() {
	s=0,f=1;
	do if(ch=='-') f=-1;
	while((ch=getchar())<48);
	do s=(s<<3)+(s<<1)+(ch^48);
	while((ch=getchar())>47);
	return s*f;
}
inline void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}
inline bool cmp(int a,int b){
	return a>b;
}
int n,m,a[1002],num,idx,posx,posy,cnt; 
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(), m=read();
	for(int i=1; i<=n*m; i++) a[i]=read();
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++){
		if(a[i]==num){
			idx=i;
			break;
		}
	}
	posx=posy=1;
	cnt=1;
	while(true){
		if(cnt==idx){
			printf("%d %d",posy,posx);
			return 0;
		}
		if(posy%2==1) ++posx;
		else --posx;
		if(posy%2==1 and posx>n) posx=n,posy++; 
		if(posy%2==0 and posx<1) posx=1,posy++;
		++cnt;
	}
	return 0;
}
