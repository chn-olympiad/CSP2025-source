#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e6+10;
int n;
int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch)){
		ch=getchar();
	}
	while(isdigit(ch)){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
void write(int x){
	if(x<10){
		putchar(x%10+'0');
		return;
	}
	write(x/10);putchar(x%10+'0');
}
struct node{
	int a,b,c,id,wh;
	friend bool operator<(node x,node y){
		int inx=0,outx=0,iny=0,outy=0;
		if(x.wh==0)inx=x.a,outx=max(x.b,x.c);
		else if(x.wh==1)inx=x.b,outx=max(x.a,x.c);
		else inx=x.c,outx=max(x.a,x.b);
		if(y.wh==0)iny=y.a,outy=max(y.b,y.c);
		else if(y.wh==1)iny=y.b,outy=max(y.a,y.c);
		else iny=y.c,outy=max(y.a,y.b);
		return inx-outx>iny-outy;
	}
}peo[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=read();
	while(t--){
		n=read();
		int res=0;
		priority_queue<node>q[3];
		for(int i=1;i<=n;i++)
			peo[i].a=read(),peo[i].b=read(),peo[i].c=read(),peo[i].id=i;
		for(int i=1;i<=n;i++){
			int maxn=max({peo[i].a,peo[i].b,peo[i].c});
			res+=maxn;
			if(maxn==peo[i].a)peo[i].wh=0,q[0].push(peo[i]);
			else if(maxn==peo[i].b)peo[i].wh=1,q[1].push(peo[i]);
			else peo[i].wh=2,q[2].push(peo[i]);
		}
		if(q[0].size()>n/2||q[1].size()>n/2||q[2].size()>n/2){
			int k=0;
			for(int i=0;i<3;i++)if(q[i].size()>n/2)k=i;
			while(q[k].size()>n/2){
				int id=q[k].top().id;
				q[k].pop();
				if(k==0)res-=peo[id].a,res+=max(peo[id].b,peo[id].c);
				else if(k==1)res-=peo[id].b,res+=max(peo[id].a,peo[id].c);
				else res-=peo[id].c,res+=max(peo[id].a,peo[id].b);
			}
		}
		write(res);
		puts("");
	}
	return 0;
}
/*
15:36 1h6min T1 过大样例
写了三坨屎山 
考前写的快读真有用快了300ms 
*/
