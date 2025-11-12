#include<bits/stdc++.h>
using namespace std;
int read(){
	char ch=getchar();
	int k=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {k=(k<<1)+(k<<3)+ch-48;ch=getchar();}
	return k*f;
}
int n,m;
int a[105],cnt,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) a[i]=read();
	for(int i=1;i<=n*m;i++) if(a[i]>a[1]) cnt++;
	cnt++;
	int w=cnt%n==0?cnt/n:cnt/n+1;
	cnt=(cnt-1)%n+1;
	if(w%2==1) printf("%d %d",w,cnt);
	else printf("%d %d",w,n-cnt+1);
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92


*/
