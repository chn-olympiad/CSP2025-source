#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define oo 
int n,T;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(int x) {
	static int st[40],top=0;
	if(x<0) {
		putchar('-');
		x=-x;
	}
	while(x) {
		st[++top]=x%10;
		x/=10;
	}
	if(top==0) st[++top]=0;
	while(top) putchar(st[top--]);
	return ;
}
struct node {
	int id,fo_1,fo_2,fo_3;
} a[N];
struct node2 {
	int id,ch;
	bool operator < (const node2 &e) const {//chazhi
		return e.ch <ch;
	}
};
priority_queue<node2>edge[3];
int ans;
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) {
		n=read();
		ans=0;
		for(int i=1; i<=n; i++) {
			a[i].fo_1 =read();
			a[i].fo_2 =read();
			a[i].fo_3 =read();
			a[i].id =i;
			if(a[i].fo_1 >=max(a[i].fo_2 ,a[i].fo_3 ))	{
				node2 now;
				now.id=i;now.ch=a[i].fo_1 -max(a[i].fo_2 ,a[i].fo_3 );
				edge[0].push(now);
			}
			else if(a[i].fo_2 >=max(a[i].fo_1 ,a[i].fo_3 )) 	{
				node2 now;
				now.id=i;now.ch=a[i].fo_2 -max(a[i].fo_3 ,a[i].fo_1 );
				edge[1].push(now);
			}
			else 	{
				node2 now;
				now.id=i;now.ch=a[i].fo_3 -max(a[i].fo_2 ,a[i].fo_1 );
				edge[2].push(now);
			}
		}
		while(edge[0].size()) {
			if(edge[0].size()<=n/2){
				ans+=a[edge[0].top().id].fo_1 ;
				edge[0].pop();
				continue;
			}
			int now=edge[0].top().id;
			edge[0].pop();
			if(a[now].fo_2 >=a[now].fo_3 )	ans+=a[now].fo_2 ;
			else ans+=a[now].fo_3 ;
		}
		while(edge[1].size()) {
			if(edge[1].size()<=n/2){
				ans+=a[edge[1].top().id].fo_2 ;
				edge[1].pop();
				continue;
			}
			int now=edge[1].top().id;
			edge[1].pop();
			if(a[now].fo_1 >=a[now].fo_3 ) ans+=a[now].fo_1 ;
			else ans+=a[now].fo_3;
			}
		while(edge[2].size()) {
			if(edge[2].size()<=n/2){
				ans+=a[edge[2].top().id].fo_3 ;
				edge[2].pop();
				continue;
			}
			int now=edge[2].top().id;
			edge[2].pop();
			if(a[now].fo_1 >=a[now].fo_2 ) ans+=a[now].fo_1 ;
			else ans+=a[now].fo_2 ;
		}	cout<<ans;
		puts("");
	}

	return 0;
}
/**
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
