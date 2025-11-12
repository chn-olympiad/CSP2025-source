#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0;bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}

int n,m,ascr,aq,r,c;

struct st{
	int scr,num;
}p[10005];

bool cmp(st a,st b){
	return a.scr>b.scr;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n*m;i++)p[i].scr=read(),p[i].num=i;
	sort(p+1,p+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(p[i].num==1){
			aq=i;
			break ;
		}
	}
	c=(aq%n==0?aq/n:aq/n+1);
	if(c%2==1)r=(aq%n==0?n:aq%n);
	else r=n-(aq%n==0?n:aq%n)+1;
	printf("%d %d",c,r);
	return 0;
}
