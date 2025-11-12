#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+10;
int a[N][3],an[3];
int minusa[N],top=0;
int t,n;
int ans=0;
int judge(int i) {
	int mx=0;
	if(a[i][mx]<a[i][1]) mx=1;
	if(a[i][mx]<a[i][2]) mx=2;
	return mx;
}
int minux(int j) {
	int mn=N,mx=0,arc=0;
	for(int i=0;i<=2;i++) {
		mn=min(mn,a[j][i]);
		mx=max(mx,a[j][i]);
		arc+=a[j][i];
	}
	return mx-(arc-mx-mn);
}
int read();
void write(int x);
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--) {
		//memset(a[0],0,sizeof(a[0]));
		//memset(a[1],0,sizeof(a[1]));
		//memset(a[2],0,sizeof(a[2]));
		memset(an,0,sizeof(an));
		n=read(); ans=0; top=0;
		for(int i=1;i<=n;i++) {
			a[i][0]=read();
			a[i][1]=read();
			a[i][2]=read();
			//sort(a[i],a[i]+3);
			/*for(int j=0;j<=2;j++)
				printf("%d ",a[i][j]);
			puts("");*/
			int mx=judge(i);
			//int mx=0;
			an[mx]++; ans+=a[i][mx];
		}
		int OK=-1,num=0;
		for(int i=0;i<=2;i++)
			if(an[i]>n/2) OK=i,num=an[i]-(n/2);
		if(OK!=-1) {
			for(int i=1;i<=n;i++) {
				if(judge(i)==OK)
					minusa[++top]=minux(i);
			}
			sort(minusa+1,minusa+top+1);
			for(int i=1;i<=num;i++)
				ans-=minusa[i];
		}
		
		write(ans);
	}
	return 0;
}
int read() {
	int Arc=0,pre=1;
	char ch=getchar();
	while(ch<48||ch>57) {
		if(ch==45) pre=-1;
	ch=getchar(); }
	while(48<=ch&&ch<=57) {
		Arc=(Arc<<3)+(Arc<<1)+(ch^48);
	ch=getchar(); }
	return Arc*pre;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	int _stack[35],_cnt=0;
	do{
		_stack[++_cnt]=x%10,x/=10;
	}while(x);
	while(_cnt) putchar(_stack[_cnt--]^48);
	puts("");
}
/*
	
*/
