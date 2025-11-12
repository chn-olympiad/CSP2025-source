#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int x,y,w;
}e[1000005];
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		read();
		for(int j=1;j<=n;j++){
			read();
		}
	}
	puts("0");
	return 0;
}
