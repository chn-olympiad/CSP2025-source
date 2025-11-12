#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[14][10010],c[14][10010];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
struct node{
	int u,v,w;
}t[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		t[i].u=read();
		t[i].v=read();
		t[i].w=read();
	}
	for(int i=1;i<=k;i++){
		c[i][0]=read();
		for(int j=1;j<=n;j++){
			c[i][j]=read();
		}
	}
	cout<<"hello world";
	return 0;
}
