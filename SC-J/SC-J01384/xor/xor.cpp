#include<bits/stdc++.h>
#define int long long 
#define fast register int
using namespace std;
const int maxn=5e6+5;

struct node{
	int l,r;
}c[maxn*3];

int n,k,a[maxn],sum,ans,cnt,lst;

bool cmp(node x,node y){
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(fast i=1;i<=n;i++){
		a[i]=read();
	}
	for(fast i=1;i<=n;i++){
		sum=0;
		for(fast j=i;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				c[++cnt].l=i;
				c[cnt].r=j;
			}
		}
	}
	sort(c+1,c+cnt+1,cmp);
	lst=0;
	for(fast i=1;i<=cnt;i++){
		if(c[i].l>lst){
			ans++;
			lst=c[i].r;
		}
	}
	write(ans);
	return 0;
}
/*
4 2
2 1 0 3
*/